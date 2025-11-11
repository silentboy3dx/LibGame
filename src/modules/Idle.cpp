#include "LibGame/module/Idle.hpp"

namespace LibGame::Module {
    bool Idle::One() const {
        return ClicIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/1.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.90f}
        );
    }

    bool Idle::Two() const {
        return ClicIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/2.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.90f}
        );
    }

    bool Idle::Three() const {
        return ClicIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/3.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.90f}
        );
    }

    bool Idle::Four() const {
        return ClicIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/4.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.90f}
        );
    }

    bool Idle::Five() const {
        return ClicIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/5.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.90f}
        );
    }

    bool Idle::Six() const {
        return ClicIfFirstAssetIsVisible(
            "idle/idle_panel_header.png",
            "idle/6.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.90f}
        );
    }
}
