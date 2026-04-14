#include "LibGame/module/Slowdance.hpp"

#include "LibGame/status/primary/ActionStatus.hpp"
#include "LibGame/status/primary/SlowDanceStatus.hpp"
#include "LibGame/module/Context.hpp"
#include "LibGame/module/Idle.hpp"

using namespace LibGame::Status::Primary;

namespace LibGame::Module {
    bool Slowdance::IsPanelVisible() const {
        return isVisible("slowdance/slowdance_panel_header.png", 0.85f, true);
    }

    bool Slowdance::Facing() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_face_to_face.png",
             DArgs(0.98f),
            DArgs(0.99f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<SlowDanceStatus>(SlowDanceStatus::Type::Facing);
        }

        return result;
    }

    bool Slowdance::Behind() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_behind.png",
             DArgs(0.98f),
            DArgs(0.99f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<SlowDanceStatus>(SlowDanceStatus::Type::Behind);
        }

        return result;
    }

    bool Slowdance::Kiss() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_kiss.png",
             DArgs(0.98f),
            DArgs(0.99f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<SlowDanceStatus>(SlowDanceStatus::Type::Kiss);
        }

        return result;
    }

    bool Slowdance::Stop() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_stop.png",
             DArgs(0.98f),
            DArgs(0.99f)
        );

        if (result) {
            core->GetInteraction<Context>()
                    .SetPrimaryStatus<SlowDanceStatus>(SlowDanceStatus::Type::Stop);
        }

        return result;
    }
}
