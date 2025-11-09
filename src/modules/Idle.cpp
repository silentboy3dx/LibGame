#include "LibGame/module/Idle.hpp"

namespace LibGame::Module {
    bool Idle::IdleOne() const {
        return ClickInCenterIfVisible("idle/1.png", 0.90f, false);
    }

    bool Idle::IdleTwo() const {
        return ClickInCenterIfVisible("idle/2.png", 0.90f, false);
    }

    bool Idle::IdleThree() const {
        return ClickInCenterIfVisible("idle/3.png", 0.90f, false);
    }

    bool Idle::IdleFour() const {
        return ClickInCenterIfVisible("idle/4.png", 0.90f, false);
    }

    bool Idle::IdleFive() const {
        return ClickInCenterIfVisible("idle/5.png", 0.90f, false);
    }

    bool Idle::IdleSix() const {
        return ClickInCenterIfVisible("idle/6.png", 0.90f, false);
    }
}
