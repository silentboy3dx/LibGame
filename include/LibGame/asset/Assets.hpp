#pragma once

#include "LibGame/Interactions.hpp"

#include <LibGraphics/LibGraphics.hpp>
#include <string>

using namespace LibGraphics;

namespace LibGame::Asset {



    class Assets final : public BaseInteraction {
    public:
        explicit Assets(Interactions *core = nullptr) : BaseInteraction(core) {}

        ~Assets() override = default;

        // Returns a cached Image reference
        Image& AssetFile(const std::string& asset) const;

        // void setAssetType(const std::string& type);
        static std::string getAssetType();
    };
}
