#pragma once

#include "LibGame/Interactions.hpp"

#include <LibIO/mouse/MouseControls.hpp>

using LibIO::Mouse::MouseControls;

namespace LibGame::Io {
    class Mouse final : public BaseInteraction {
    public:
        explicit Mouse(Interactions *core);
        ~Mouse() override = default;

        void Scroll(int amount, int *x = nullptr, int *y = nullptr) ;

        void ScrollUp(int amount = 1) ;

        void ScrollDown(int amount = 1) ;

        void Click() ;

        void RightClick() ;

        void MoveTo(int x = 0, int y = 0) ;

        void MoveToAndClick(int x = 0, int y = 0) ;

        void MoveToAndRightClick(int x = 0, int y = 0) ;

        void MoveToAndExit(int x = 0, int y = 0, int exitcode = 0) ;
    };
}
