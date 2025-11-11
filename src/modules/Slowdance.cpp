#include "LibGame/module/Slowdance.hpp"

namespace LibGame::Module {
    bool Slowdance::IsPanelVisible() const {
        return isVisible("slowdance/slowdance_panel_header.png", 0.85f, true);
    }

    bool Slowdance::Facing() const {
        return ClicIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_face_to_face.png",
            DArgs{.confidence = 0.98f},
            DArgs{.confidence = 0.99f}
        );
    }

    bool Slowdance::Behind() const {
        return ClicIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_behind.png",
            DArgs{.confidence = 0.98f},
            DArgs{.confidence = 0.99f}
        );
    }

    bool Slowdance::Kiss() const {
        return ClicIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_kiss.png",
            DArgs{.confidence = 0.98f},
            DArgs{.confidence = 0.99f}
        );
    }

    bool Slowdance::Stop() const {
        return ClicIfFirstAssetIsVisible(
            "slowdance/slowdance_panel_header.png",
            "slowdance/button_stop.png",
            DArgs{.confidence = 0.98f},
            DArgs{.confidence = 0.99f}
        );
    }
}
