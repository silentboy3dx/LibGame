#pragma once

#include "LibGame/Interactions.hpp"

#include <LibIO/mouse/MouseControls.hpp>

using LibIO::Mouse::MouseControls;

namespace LibGame::Io {
    class Mouse final : public BaseInteraction {
    public:
        explicit Mouse(Interactions *core);
        ~Mouse() override = default;

        static void Scroll(int amount, int *x = nullptr, int *y = nullptr) ;

        static void ScrollUp(int amount = 1) ;

        static void ScrollDown(int amount = 1) ;

        static void Click() ;

        static void RightClick() ;

        static void MoveTo(int x = 0, int y = 0) ;

        static void MoveToAndClick(int x = 0, int y = 0) ;

        static void MoveToAndRightClick(int x = 0, int y = 0) ;

        static void MoveToAndExit(int x = 0, int y = 0, int exitcode = 0) ;
    };
}
