#include "LibGame/module/Strapon.hpp"

#include "LibGame/statuses/secondary/StraponSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using namespace LibGame::Statuses::Secondary;

namespace LibGame::Module {
    bool Strapon::Off() const {
        return ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_off.png",
            DArgs(0.99f, false, false, true),
            DArgs(0.98f, true, false, true)
        );
    }

    bool Strapon::Penis() const {
        return ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_penis.png",
            DArgs(0.99f, false, false, true),
            DArgs(0.98f, false, false, true)
        );
    }

    bool Strapon::Toy1() const {
        return ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_strapon_1.png",
            DArgs(0.99f, false, false, true),
            DArgs(0.98f, false, false, true)
        );
    }

    bool Strapon::Toy2() const {
        return ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_strapon_2.png",
            DArgs(0.99f, false, false, true),
            DArgs(0.98f, false, false, true)
        );
    }
}
