#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Movement final : public BaseModule {
    public:
        explicit Movement(Interactions *core) : BaseModule(core) {
        };

        ~Movement() override = default;

        bool Run() const;
        bool Walk() const;
    };
}
