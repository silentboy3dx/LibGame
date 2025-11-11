#include "LibGame/module/Movement.hpp"

namespace LibGame::Module {
    bool Movement::Run() const {
        return ClicIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_run.png",
            DArgs{.confidence = 0.99f},
            DArgs{.grayscale = true, .confidence = 0.93f}
        );
    }

    bool Movement::Walk() const {
        return ClicIfFirstAssetIsVisible(
            "movement/movement_panel_header.png",
            "movement/button_walk.png",
            DArgs{.confidence = 0.99f},
            DArgs{.grayscale = true, .confidence = 0.93f}
        );
    }
}
