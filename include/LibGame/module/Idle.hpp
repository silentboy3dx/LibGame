#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Idle final : public BaseModule {
    public:
        explicit Idle(Interactions *core): BaseModule(core) {};

        ~Idle() override = default;

        bool One() const;
        bool Two() const;
        bool Three() const;
        bool Four() const;
        bool Five() const;
        bool Six() const;
    };
}