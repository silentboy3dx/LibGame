#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Clothing final : public BaseModule {
    public:
        explicit Clothing(Interactions *core) : BaseModule(core) {
        };

        ~Clothing() override = default;

        bool OpenPanel() const;
        bool ClosePanel() const;

        bool IsWet() const;
        bool IsDry() const;

        bool PutAllOn() const;
        bool TakeAllOff() const;
        bool Wet() const;
        bool Dry() const;
        bool ToggleWetness() const;

    private:
        bool isPanelOpen() const;
    };
}
