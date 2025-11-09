#include <LibGame/io/Screenshot.hpp>

#include <LibScreenshots.hpp>

namespace LibGame::Io {
    ScreenshotResult Screenshot::Take() {
        return TakeScreenshot();
    }

    ScreenshotResult Screenshot::Take(const int x, const int y, const int width, const int height) {
        return TakeScreenshot(x, y, width, height);
    }
}