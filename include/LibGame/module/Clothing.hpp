#pragma once

#include "BaseModule.hpp"

using namespace LibGame::Detect;
using namespace LibGame::Asset;

namespace LibGame::Module {
    class Clothing final : public BaseModule {
    public:
        explicit Clothing(Interactions *core) : BaseModule(core) {
        };

        ~Clothing() override = default;

        void OpenPanel() const;
        void ClosePanel() const;

        bool IsWet() const;
        bool IsDry() const;

        void PutAllOn() const;
        void TakeAllOff() const;
        void Wet() const;
        void Dry() const;
        void ToggleWetness() const;

    private:
        bool isPanelOpen() const;
    };
}
