#pragma once

#include <LibGraphics/type/Region.hpp>

using namespace LibGraphics::Type;

namespace LibGame::Misc {
    class Point {
    public:
        explicit Point(const int x = 0, const int y = 0) :X(x), Y(y) {}
        int X = 0;
        int Y = 0;

    };
}