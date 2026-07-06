#include "LibGame/module/Slowdance.hpp"
#include "LibGame/module/Context.hpp"

namespace LibGame::Module {
    bool Slowdance::IsPanelVisible() const {
        return isVisible("slowdance/slowdance_panel_header.png", 0.85f, true);
    }

    bool Slowdance::Facing() const {
        return ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_face_to_face.png",
             DArgs(0.98f,false, false, false),
            DArgs(0.98f,false, false, false)
        );
    }

    bool Slowdance::Behind() const {
        return ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_behind.png",
             DArgs(0.98f,false, false, false),
            DArgs(0.98f,false, false, false)
        );
    }

    bool Slowdance::Kiss() const {
        return  ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_kiss.png",
             DArgs(0.98f, false, false, false),
            DArgs(0.98f, false, false, false)
        );
    }

    bool Slowdance::Stop() const {
        return ClickIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_stop.png",
             DArgs(0.98f,false, false, false),
            DArgs(0.98f,false, false, false)
        );
    }
}
