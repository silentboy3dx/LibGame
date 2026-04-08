#include "LibGame/asset/Assets.hpp"

#include <LibGraphics/LibGraphics.hpp>

#include <filesystem>
#include <stdexcept>
#include <cstdlib>
#include <string>

#pragma warning("Move GetEnvString to LibOS")

using namespace LibGraphics;

namespace LibGame::Asset {

    // ------------------------------------------------------------
    // Portable environment variable reader (Windows + Linux/macOS)
    // ------------------------------------------------------------
    static std::string GetEnvString(const char* name) {
    #if defined(_WIN32)
        char* buffer = nullptr;
        size_t size = 0;

        if (_dupenv_s(&buffer, &size, name) == 0 && buffer != nullptr) {
            std::string value(buffer);
            free(buffer);
            return value;
        }
        return "";
    #else
        const char* val = std::getenv(name);
        return val ? std::string(val) : "";
    #endif
    }

    // ------------------------------------------------------------
    // Asset loading
    // ------------------------------------------------------------

    Image& Assets::AssetFile(const std::string& asset) {

        // Return cached asset if already loaded
        if (cache.contains(asset)) {
            return cache[asset];
        }

        // Read environment variable safely
        std::string assetPath = GetEnvString("LIBGAME_ASSET_PATH");

        if (assetPath.empty()) {
            throw std::runtime_error("LIBGAME_ASSET_PATH not set");
        }

        // Build full path
        const std::string fullPath = assetPath + "/" + assetType + "/" + asset;

        // Check if file exists
        if (!std::filesystem::exists(fullPath)) {
            throw std::runtime_error("Asset file does not exist: " + fullPath);
        }

        // Load into cache
        cache[asset] = Image::load(fullPath);

        return cache[asset];
    }

    // ------------------------------------------------------------
    // Asset type getters/setters
    // ------------------------------------------------------------

    std::string Assets::getAssetType() const {
        return assetType;
    }

    void Assets::setAssetType(const std::string& type) {
        assetType = type;
    }

}
