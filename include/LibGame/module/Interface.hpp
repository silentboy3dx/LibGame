#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Interface final : public BaseModule {
    public:
        explicit Interface(Interactions *core) : BaseModule(core) {
        };

        ~Interface() override = default;

        void HideInterface() const;
        void ShowInterface() const;
    };
}
