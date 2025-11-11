#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Slowdance final : public BaseModule {
    public:
        explicit Slowdance(Interactions *core) : BaseModule(core) {};
        ~Slowdance() override = default;

        bool IsPanelVisible() const;
        bool Facing() const;
        bool Behind() const;
        bool Kiss() const;
        bool Stop() const;

    private:

    };
}
