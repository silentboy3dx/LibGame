#include "LibGame/io/Mouse.hpp"

#include <iostream>
#include <LibIO/LibIO.hpp>

using namespace LibIO;

namespace LibGame::Io {
    Mouse::Mouse(Interactions *core) : BaseInteraction(core) {
        // Empty for now
    }

    void Mouse::Scroll(const int amount, int *x, int *y) {
        GetMouseControls()
                ->Scroll(
                    amount,
                    x,
                    y);
    }

    void Mouse::ScrollUp(const int amount) {
        GetMouseControls()
                ->ScrollUp(amount);
    }

    void Mouse::ScrollDown(const int amount) {
        GetMouseControls()
                ->ScrollDown(amount);
    }

    void Mouse::Click() {
        GetMouseControls()
                ->LeftClick();
    }

    void Mouse::RightClick() {
        GetMouseControls()
                ->RightClick();
    }

    void Mouse::MoveTo(const int x, const int y) {
        GetMouseControls()
                ->MoveCursor(x, y);
    }

    void Mouse::MoveToAndClick(const int x, const int y) {
        GetMouseControls()->MoveAndLeftClick(
            x,
            y
        );
    }

    void Mouse::MoveToAndRightClick(const int x, const int y) {
        GetMouseControls()->MoveAndRightClick(
            x,
            y
        );
    }

    void Mouse::MoveToAndExit(const int x, const int y, const int exitcode) {
        GetMouseControls()->MoveCursor(x, y);
        exit(exitcode);
    }
}
