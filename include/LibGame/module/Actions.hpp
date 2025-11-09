#pragma once

#include "BaseModule.hpp"

using namespace LibGame::Detect;

namespace LibGame::Module {
    class Actions final : public BaseModule {
    public:
        explicit Actions(Interactions *core) : BaseModule(core) {};

        ~Actions() override = default;

        bool SitOne() const;
        bool SitTwo() const;
        bool LieOne() const;
        bool LieTwo() const;
        bool Hello() const;
        bool Applause() const;
    };
}

