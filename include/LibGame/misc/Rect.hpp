#pragma once

#include <LibGraphics/type/Region.hpp>

using namespace LibGraphics::Type;

namespace LibGame::Misc {
    class Rect : public Region {
    public:
        explicit Rect(const int x = 0, const int y = 0, const int width = 0, const int height = 0)
            : Region(x, y, width, height) {
        }

        [[nodiscard]] Rect Center() const {
            const int cx = X + Width / 2;
            const int cy = Y + Height / 2;
            return Rect(cx, cy, Width, Height);
        }
    };
}