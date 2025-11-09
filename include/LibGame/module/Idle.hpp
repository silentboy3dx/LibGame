#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Idle final : public BaseModule {
    public:
        explicit Idle(Interactions *core): BaseModule(core) {};

        ~Idle() override = default;

        bool IdleOne() const;
        bool IdleTwo() const;
        bool IdleThree() const;
        bool IdleFour() const;
        bool IdleFive() const;
        bool IdleSix() const;
    };
}