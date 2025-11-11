#include "LibGame/module/Item.hpp"

namespace LibGame::Module {
    bool Item::Consume() const {
        return ClicIfFirstAssetIsVisible(
            "item/holding_panel_header.png",
            "item/button_use.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.85f}
        );
    }

    bool Item::PutAway() const {
        return ClicIfFirstAssetIsVisible(
            "item/holding_panel_header.png",
            "item/button_remove.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.85f}
        );
    }

    bool Item::Drop() const {
        return ClicIfFirstAssetIsVisible(
            "item/holding_panel_header.png",
            "item/button_throw.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.85f}
        );
    }
}
