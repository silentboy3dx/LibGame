#include "LibGame/module/Idle.hpp"

#include "LibGame/statuses/primary/IdlePrimaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Statuses::Primary::IdlePrimaryStatus;

namespace LibGame::Module {
    class Context;

    bool Idle::One() const {
        return ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/1.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );
    }

    bool Idle::Two() const {
        return  ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/2.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );
    }

    bool Idle::Three() const {
        return ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/3.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );
    }

    bool Idle::Four() const {
        return ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/4.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );
    }

    bool Idle::Five() const {
        return ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/5.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );
    }

    bool Idle::Six() const {
        return ClickIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/6.png",
             DArgs(0.98f),
             DArgs(0.90f)
        );
    }
}
