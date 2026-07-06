#include "LibGame/module/Movement.hpp"

#include "LibGame/statuses/secondary/MovementSpeedSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using namespace LibGame::Statuses::Secondary;

namespace LibGame::Module {
    bool Movement::Run() const {
        return ClickIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_run.png",
            DArgs(0.98f, false, false, false),
           DArgs(0.93f, true, false, false)
        );
    }

    bool Movement::Walk() const {
         return ClickIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_walk.png",
            DArgs(0.98f, false, false, false),
           DArgs(0.93f, true, false, false)
        );
    }
}
