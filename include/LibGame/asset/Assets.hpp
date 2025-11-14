#pragma once

#include "LibGame/Interactions.hpp"

#include <LibGraphics.hpp>
#include <string>

using namespace LibGraphics;

namespace LibGame::Asset {
    struct AssetType {
        inline static auto TYPE_2K = "2K";
        inline static auto TYPE_4K = "4K";
    };

    class Assets final : public BaseInteraction {
    public:
        explicit Assets(Interactions *core = nullptr) : BaseInteraction(core) {};

        ~Assets() override = default;

        Image &AssetFile(const std::string &asset);

        void setAssetType(const std::string &type);
        std::string getAssetType() const;

    private:
        std::string assetType = AssetType::TYPE_2K;
        std::unordered_map<std::string, Image> cache;
    };
}
