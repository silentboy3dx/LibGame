#include "LibGame/module/Strapon.hpp"

namespace LibGame::Module {
    bool Strapon::Off() const {
        return ClicIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_off.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );
    }

    bool Strapon::Penis() const {
        return ClicIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_penis.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );
    }

    bool Strapon::Toy1() const {
        return ClicIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_strapon_1.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );
    }

    bool Strapon::Toy2() const {
        return ClicIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_strapon_2.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );
    }
}
