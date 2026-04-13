#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

#include <LibGraphics/LibGraphics.hpp>
#include <LibOS/LibOS.hpp>

#include "LibGame/asset/AssetCache.hpp"
#include "LibGame/LibGame.hpp"

using json = nlohmann::json;
using namespace LibGraphics;
using LibGame::Exceptions::AssetException;

namespace LibGame::Asset {

static std::string assetType = AssetType::TYPE_2K;

AssetCache& AssetCache::Instance() {
    static AssetCache instance;
    return instance;
}

std::string AssetCache::NormalizePath(const std::string& path) {
    std::string out = path;
    for (char& c : out) {
        if (c == '\\') c = '/';
    }
    return out;
}

std::string AssetCache::BuildFullPath(const std::string& relativePath) {
    auto envPathOpt = LibOS::GetEnv("LIBGAME_ASSET_PATH");
    if (!envPathOpt.has_value()) {
        throw AssetException("LIBGAME_ASSET_PATH not set", typeid(Image).name());
    }

    const std::string& assetPath = envPathOpt.value();
    const std::string normalized = NormalizePath(relativePath);

    return assetPath + "/" + assetType + "/" + normalized;
}

std::shared_ptr<Image> AssetCache::Load(const std::string& givenPath) {
    const std::string normalized = NormalizePath(givenPath);
    const std::string fullPath = BuildFullPath(normalized);

    std::filesystem::path p = std::filesystem::weakly_canonical(fullPath);
    const std::string key = p.string();

    auto it = cache.find(key);
    if (it != cache.end()) {
        return it->second;
    }

    auto img = std::make_shared<Image>(Image::load(key));
    img->mat();

    cache[key] = img;
    return img;
}

void AssetCache::PreloadAll() {
    auto envPathOpt = LibOS::GetEnv("LIBGAME_DATA_PATH");
    if (!envPathOpt.has_value()) {
        throw AssetException("LIBGAME_DATA_PATH not set", typeid(Image).name());
    }

    const std::string& assetPath = envPathOpt.value();
    const std::string preloadFile = assetPath + "/preload.json";

    if (!std::filesystem::exists(preloadFile)) {
        throw AssetException("preload.json not found at: " + preloadFile,
                             typeid(Image).name());
    }

    std::ifstream f(preloadFile);
    json j;
    f >> j;

    if (!j.contains("preload") || !j["preload"].is_array()) {
        throw AssetException("Invalid preload.json format", typeid(Image).name());
    }

    for (const auto& entry : j["preload"]) {
        if (!entry.is_string()) continue;
        Load(entry.get<std::string>());
    }
}

bool AssetCache::Has(const std::string& relativePath) const {
    const std::string fullPath = BuildFullPath(relativePath);
    std::filesystem::path p = std::filesystem::weakly_canonical(fullPath);
    return cache.contains(p.string());
}

void AssetCache::Remove(const std::string& relativePath) {
    const std::string fullPath = BuildFullPath(relativePath);
    std::filesystem::path p = std::filesystem::weakly_canonical(fullPath);
    cache.erase(p.string());
}

void AssetCache::Clear() {
    cache.clear();
}

void AssetCache::PrintCache() const {
    for (const auto& [key, img] : cache) {
        std::cout << key;
        if (img && img->isValid()) {
            std::cout << "  ("
                      << img->width << "x"
                      << img->height << ", "
                      << img->channels << "ch)";
        } else {
            std::cout << "  (invalid)";
        }
        std::cout << "\n";
    }
}

std::string AssetCache::getAssetType() const {
    return assetType;
}

} // namespace LibGame::Asset
