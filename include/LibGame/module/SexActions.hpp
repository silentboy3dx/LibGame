#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class SexActions final : public BaseModule {
    public:
        explicit SexActions(Interactions *core) : BaseModule(core) {};
        ~SexActions() override = default;

        bool Moan() const;
        bool Cum() const;
    };
}
