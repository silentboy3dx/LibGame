#pragma once

#include "LibGame/Interactions.hpp"
#include <LibScreenshots/LibScreenshots.hpp>
#include <LibGraphics/LibGraphics.hpp>

using namespace LibScreenshots;

namespace LibGame::Io {
    class Screenshot final: public BaseInteraction {
    public:
        explicit Screenshot(Interactions *core) : BaseInteraction(core) {};

        Image Take();
        Image Take(int x, int y, int width, int height);
    };
}
