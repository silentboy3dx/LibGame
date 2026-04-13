#include "LibGame/module/Actions.hpp"

namespace LibGame::Module {
    bool Actions::Sit1() const {
        return ClickIfFirstAssetIsVisible(
            "actions/actions_panel_header.png",
            "actions/button_sit1.png",
            DArgs(0.99f),
             DArgs(0.90f)
        );
    }

    bool Actions::Sit2() const {
        return ClickIfFirstAssetIsVisible(
            "actions/actions_panel_header.png",
            "actions/button_sit2.png",
            DArgs(0.99f),
             DArgs(0.90f)
        );
    }

    bool Actions::Lie1() const {
        return ClickIfFirstAssetIsVisible(
            "actions/actions_panel_header.png",
            "actions/button_lie1.png",
            DArgs(0.99f),
             DArgs(0.90f)
        );
    }

    bool Actions::Lie2() const {
        return ClickIfFirstAssetIsVisible(
            "actions/actions_panel_header.png",
            "actions/button_lie2.png",
            DArgs(0.99f),
             DArgs(0.90f)
        );
    }

    bool Actions::Hello() const {
        return ClickIfFirstAssetIsVisible(
            "actions/actions_panel_header.png",
            "actions/button_hello.png",
            DArgs(0.99f),
             DArgs(0.90f)
        );
    }

    bool Actions::Applause() const {
        return ClickIfFirstAssetIsVisible(
            "actions/actions_panel_header.png",
            "actions/button_applause.png",
            DArgs(0.99f),
             DArgs(0.90f)
        );
    }
}
