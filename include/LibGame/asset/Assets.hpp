#pragma once

#include <iostream>

#include "LibGame/Interactions.hpp"

#include <LibGraphics/LibGraphics.hpp>
#include <string>

using namespace LibGraphics;

using LibGame::BaseInteraction;
using LibGame::Interactions;

namespace LibGame::Asset {

    class Assets final : public BaseInteraction {
    public:
        explicit Assets(Interactions *core = nullptr) : BaseInteraction(core) {}

        ~Assets() override = default;

        Image& AssetFile(const std::string& asset) const ;

        static std::string getAssetType();

        void setDebug(bool enable);

    private:
        bool _debug = true;
    };
}
