#include "LibGame/asset/Assets.hpp"
#include "LibGame/LibGame.hpp"
#include "LibOS/LibOS.hpp"

#include <LibGraphics/LibGraphics.hpp>

#include <filesystem>
#include <stdexcept>
#include <string>

using LibGame::Exceptions::AssetException;
using namespace LibGraphics;

namespace LibGame::Asset {


    // ------------------------------------------------------------
    // Asset loading
    // ------------------------------------------------------------

    Image &Assets::AssetFile(const std::string &asset) {
        // Return cached asset if already loaded
        if (cache.contains(asset)) {
            return cache[asset];
        }

        auto envPathOpt = LibOS::GetEnv("LIBGAME_DATA_PATH");
        if (!envPathOpt.has_value()) {
            throw AssetException("LIBGAME_DATA_PATH not set", typeid(Image).name());
        }

        const std::string& assetPath = envPathOpt.value();
        const std::string fullPath = assetPath + "/" + assetType + "/" + asset;

        if (!std::filesystem::exists(fullPath)) {
            throw std::runtime_error("Asset file does not exist: " + fullPath);
        }

        cache[asset] = Image::load(fullPath);

        return cache[asset];
    }

    std::string Assets::getAssetType() const {
        return assetType;
    }

    void Assets::setAssetType(const std::string &type) {
        assetType = type;
    }
}
