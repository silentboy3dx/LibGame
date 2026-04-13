#include "LibGame/module/Item.hpp"

namespace LibGame::Module {
    bool Item::Consume() const {
        return ClickIfFirstAssetIsVisible(
            "item/holding_panel_header.png",
            "item/button_use.png",
            DArgs(0.99f),
             DArgs(0.85f)
        );
    }

    bool Item::PutAway() const {
        return ClickIfFirstAssetIsVisible(
            "item/holding_panel_header.png",
            "item/button_remove.png",
            DArgs(0.99f),
             DArgs(0.85f)
        );
    }

    bool Item::Drop() const {
        return ClickIfFirstAssetIsVisible(
            "item/holding_panel_header.png",
            "item/button_throw.png",
            DArgs(0.99f),
             DArgs(0.85f)
        );
    }
}
