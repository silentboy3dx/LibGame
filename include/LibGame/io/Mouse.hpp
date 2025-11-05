#pragma once

#include "LibGame/Interactions.hpp"

#include <LibIO/mouse/MouseControls.hpp>

using LibIO::Mouse::MouseControls;

namespace LibGame::Io {
    class Mouse final : public BaseInteraction {
    public:
        explicit Mouse(Interactions *core);
        ~Mouse() override;

        void Scroll(int amount, int *x = nullptr, int *y = nullptr) const;

        void ScrollUp(int amount = 1) const;

        void ScrollDown(int amount = 1) const;

        void Click() const;

        void RightClick() const;

        void MoveTo(int x = 0, int y = 0) const;

        void MoveToAndClick(int x = 0, int y = 0) const;

        void MoveToAndRightClick(int x = 0, int y = 0) const;

        void MoveToAndExit(int x = 0, int y = 0, int exitcode = 0) const;

    private:
        MouseControls *controller;
    };
}
