#include "LibGame/module/Movement.hpp"

#include "LibGame/status/secondary/MovementSpeedSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using namespace LibGame::Status::Secondary;

namespace LibGame::Module {
    bool Movement::Run() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_run.png",
            DArgs(0.99f),
           DArgs(0.93f, true)
        );


        if (result) {
            core->GetInteraction<Context>()
            .AddSecondaryStatus<MovementSpeedSecondaryStatus>(MovementSpeedSecondaryStatus::Type::Running);
        }

        return result;
    }

    bool Movement::Walk() const {
         const auto result =  ClickIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_walk.png",
            DArgs(0.99f),
           DArgs(0.93f, true)
        );

        if (result) {
            core->GetInteraction<Context>()
            .AddSecondaryStatus<MovementSpeedSecondaryStatus>(MovementSpeedSecondaryStatus::Type::Walking);
        }

        return result;
    }
}
