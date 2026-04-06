#pragma once

#include "BaseModule.hpp"

using namespace LibGame::Detect;

namespace LibGame::Module {
    class Actions final : public BaseModule {
    public:
        explicit Actions(Interactions *core) : BaseModule(core) {};

        ~Actions() override = default;

        bool Sit1() const;
        bool Sit2() const;
        bool Lie1() const;
        bool Lie2() const;
        bool Hello() const;
        bool Applause() const;
    };
}

