#pragma once

#include "LibGame/Interactions.hpp"

#include <LibScreenshots.hpp>

using namespace LibScreenshots;

namespace LibGame::Io {
    class Screenshot final: public BaseInteraction {
    public:
        explicit Screenshot(Interactions *core) : BaseInteraction(core) {};

        ScreenshotResult Take();

        ScreenshotResult Take(int x, int y, int width, int height);
    };
}
