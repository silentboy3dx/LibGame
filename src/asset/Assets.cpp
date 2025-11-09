#include "LibGame/asset/Assets.hpp"

#include <LibGraphics.hpp>

#include <filesystem>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace LibGraphics;

namespace LibGame::Asset {
    Image &Assets::AssetFile(const std::string &asset) {

        if (cache.contains(asset)) {
            return cache[asset];
        }

        const char* assetPath = std::getenv("LIBGAME_ASSET_PATH");

        if (assetPath == nullptr) {
            throw std::runtime_error("LIBGAME_ASSET_PATH not set");
        }

        const std::string fullPath = std::string(assetPath) + "/" + assetType + "/" + asset;

        if (!std::filesystem::exists(fullPath)) {
            throw std::runtime_error("Asset file does not exist: " + fullPath);
        }

        if (!cache.contains(asset)) {
            cache[asset] = Image::load(fullPath);
        }

        return cache[asset];
    }

    void Assets::setAssetType(const std::string &type) {
        assetType = type;
    }
}
