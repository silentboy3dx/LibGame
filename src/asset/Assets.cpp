#include "LibGame/asset/Assets.hpp"
#include "LibGame/asset/AssetCache.hpp"
#include "LibGame/LibGame.hpp"

#include <string>

#include "../../../LibCore/include/LibCore/report/Reporter.hpp"

using LibGame::Exceptions::AssetException;
using LibCore::Report::Reporter;
using LibCore::Report::arg;

namespace LibGame::Asset {

    Image& Assets::AssetFile(const std::string& asset) const {
        auto& cache = AssetCache::Instance();

        if (!cache.Has(asset)) {
            if (_debug) {
                // cache.PrintCache();
                Reporter::Verbose("Asset not preloaded: {asset}",
                    typeid(Assets).name(),
                    arg("asset", asset));
            }
        }

        auto imgPtr = cache.Load(asset);

        return *imgPtr;
    }

    std::string Assets::getAssetType() {
        return AssetCache::Instance().getAssetType();
    }

    void Assets::setDebug(bool enable) {
        _debug = enable;
    }
}
