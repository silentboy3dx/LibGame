#include <LibGame/io/Screenshot.hpp>

namespace LibGame::Io {
    Image Screenshot::Take() {
        return TakeScreenshot();
    }

    Image Screenshot::Take(const int x, const int y, const int width, const int height) {
        return TakeScreenshot(x, y, width, height);
    }
}
