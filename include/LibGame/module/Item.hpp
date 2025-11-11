#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Item final : public BaseModule {
    public:
        explicit Item(Interactions *core) : BaseModule(core) {
        };

        ~Item() override = default;

        bool Consume() const;
        bool PutAway() const;
        bool Drop() const;
    };
}
