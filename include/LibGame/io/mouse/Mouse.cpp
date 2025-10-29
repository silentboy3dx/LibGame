#include "LibGame/io/mouse/Mouse.hpp"
#include <LibIO/LibIO.hpp>

using namespace LibIO;

namespace LibGame::Io {

    Mouse::Mouse() {
        Controller = GetMouseControls();
    }

    Mouse::~Mouse() {
        delete Controller;
    }

    void Mouse::Scroll(const int amount, int *x, int *y) const {
        Controller
                ->Scroll(
                    amount,
                    x,
                    y);
    }

    void Mouse::ScrollUp(const int amount) const {
        Controller
                ->ScrollUp(amount);
    }

    void Mouse::ScrollDown(const int amount) const {
        Controller
                ->ScrollDown(amount);
    }

    // Click functions
    void Mouse::Click() const {
        Controller
                ->LeftClick();
    }

    void Mouse::RightClick() const {
        Controller
                ->RightClick();
    }

    void Mouse::MoveTo(const int x, const int y) const {
        Controller
                ->MoveCursor(x, y);
    }

    void Mouse::MoveToAndClick(const int x, const int y) const {
        Controller->MoveAndLeftClick(
            x,
            y
        );
    }

    void Mouse::MoveToAndRightClick(const int x, const int y) const {
        Controller->MoveAndRightClick(
            x,
            y
        );
    }

    void Mouse::MoveToAndExit(const int x, const int y, const int exitcode) const {
        Controller->MoveCursor(x, y);
        exit(exitcode);
    }
}
