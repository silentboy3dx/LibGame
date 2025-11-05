#pragma once

#include <LibGraphics/match/Region.hpp>

using namespace LibGraphics::Match;

class Point : public Region {
public:
    explicit Point(const int x = 0, const int y = 0, const int width = 0, const int height = 0)
        : Region(x, y, width, height) {
    }

    [[nodiscard]] Point Center() const {
        const int cx = X + Width / 2;
        const int cy = Y + Height / 2;
        return Point(cx, cy, Width, Height);
    }
};
