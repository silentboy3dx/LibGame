#include "LibGame/module/Movement.hpp"

#include "LibGame/action/secondary/MovementSpeedSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using namespace LibGame::Action::Secondary;

namespace LibGame::Module {
    bool Movement::Run() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_run.png",
            DArgs{.confidence = 0.99f},
            DArgs{.grayscale = true, .confidence = 0.93f}
        );


        if (result) {
            core->GetInteraction<Context>()
            .AddSecondaryAction<MovementSpeedSecondaryStatus>(MovementSpeedSecondaryStatus::Type::Running);
        }

        return result;
    }

    bool Movement::Walk() const {
         const auto result =  ClickIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_walk.png",
            DArgs{.confidence = 0.99f},
            DArgs{.grayscale = true, .confidence = 0.93f}
        );

        if (result) {
            core->GetInteraction<Context>()
            .AddSecondaryAction<MovementSpeedSecondaryStatus>(MovementSpeedSecondaryStatus::Type::Walking);
        }

        return result;
    }
}
