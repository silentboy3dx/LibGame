#include "LibGame/module/Idle.hpp"

#include "LibGame/statuses/primary/IdlePrimaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Statuses::Primary::IdlePrimaryStatus;

namespace LibGame::Module {
    class Context;

    bool Idle::One() const {
        const bool result = ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/1.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle1);
        }

        return result;
    }

    bool Idle::Two() const {
        const bool result = ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/2.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle2);
        }

        return result;
    }

    bool Idle::Three() const {
        const bool result = ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/3.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle3);
        }

        return result;
    }

    bool Idle::Four() const {
        const bool result = ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/4.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle4);
        }

        return result;
    }

    bool Idle::Five() const {
        const bool result = ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/5.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle5);
        }

        return result;
    }

    bool Idle::Six() const {
        const bool result = ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/6.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle6);
        }

        return result;
    }
}
