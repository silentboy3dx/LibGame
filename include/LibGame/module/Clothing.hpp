#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Clothing final : public BaseModule {
    public:
        explicit Clothing(Interactions *core) : BaseModule(core) {
        };

        ~Clothing() override = default;

        [[nodiscard]] bool OpenPanel() const;
        [[nodiscard]] bool ClosePanel() const;

        [[nodiscard]] bool IsWet() const;
        [[nodiscard]] bool IsDry() const;

        [[nodiscard]] bool DressAll() const;
        [[nodiscard]] bool UnDressAll() const;
        [[nodiscard]] bool Wet() const;
        [[nodiscard]] bool Dry() const;
        [[nodiscard]] bool ToggleWetness() const;

    private:
        [[nodiscard]] bool isPanelOpen() const;
    };
}
