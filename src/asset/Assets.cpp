#include <LibGraphics/LibGraphics.hpp>

#include <filesystem>
#include <string>

#include "LibGame/asset/Assets.hpp"
#include "LibGame/asset/AssetCache.hpp"
#include "LibGame/LibGame.hpp"


using LibGame::Exceptions::AssetException;
using namespace LibGraphics;

namespace LibGame::Asset {

    Image& Assets::AssetFile(const std::string& asset) const {
        auto& cache = AssetCache::Instance();

        if (!cache.Has(asset)) {
            cache.PrintCache();
            std::cerr << "Asset not preloaded: " << asset << std::endl;
        }

        auto imgPtr = cache.Load(asset);

        return *imgPtr;
    }

    std::string Assets::getAssetType() {
        return AssetCache::Instance().getAssetType();
    }

}
