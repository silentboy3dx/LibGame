#include "LibGame/io/Mouse.hpp"

#include <LibIO/LibIO.hpp>

using namespace LibIO;

namespace LibGame::Io {
    Mouse::Mouse(Interactions *core) : BaseInteraction(core) {
        controller = GetMouseControls();
    }

    Mouse::~Mouse() {
        delete controller;
    }

    void Mouse::Scroll(const int amount, int *x, int *y) const {
        controller
                ->Scroll(
                    amount,
                    x,
                    y);
    }

    void Mouse::ScrollUp(const int amount) const {
        controller
                ->ScrollUp(amount);
    }

    void Mouse::ScrollDown(const int amount) const {
        controller
                ->ScrollDown(amount);
    }

    // Click functions
    void Mouse::Click() const {
        controller
                ->LeftClick();
    }

    void Mouse::RightClick() const {
        controller
                ->RightClick();
    }

    void Mouse::MoveTo(const int x, const int y) const {
        controller
                ->MoveCursor(x, y);
    }

    void Mouse::MoveToAndClick(const int x, const int y) const {
        controller->MoveAndLeftClick(
            x,
            y
        );
    }

    void Mouse::MoveToAndRightClick(const int x, const int y) const {
        controller->MoveAndRightClick(
            x,
            y
        );
    }

    void Mouse::MoveToAndExit(const int x, const int y, const int exitcode) const {
        controller->MoveCursor(x, y);
        exit(exitcode);
    }
}
