#include "LibGame/asset/Assets.hpp"
#include "LibGame/asset/AssetCache.hpp"
#include "LibGame/LibGame.hpp"

#include <string>

using LibGame::Exceptions::AssetException;

namespace LibGame::Asset {
    Image &Assets::AssetFile(const std::string &asset) const {
        auto &cache = AssetCache::Instance();

        Verbose("HI");
        if (!cache.Has(asset)) {
            Verbose("Asset not preloaded: " + asset);
        }

        auto imgPtr = cache.Load(asset);

        return *imgPtr;
    }

    std::string Assets::getAssetType() {
        return AssetCache::Instance().getAssetType();
    }
}
