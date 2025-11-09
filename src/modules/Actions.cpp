#include "LibGame/module/Actions.hpp"

namespace LibGame::Module  {

    bool Actions::SitOne() const {
        return ClickInCenterIfVisible("actions/button_sit1.png", 0.90f, false);
    }

    bool Actions::SitTwo() const {
        return ClickInCenterIfVisible("actions/button_sit2.png", 0.90f, false);
    }

    bool Actions::LieOne() const {
        return ClickInCenterIfVisible("actions/button_lie1.png", 0.90f, false);
    }

    bool Actions::LieTwo() const {
        return ClickInCenterIfVisible("actions/button_lie2.png", 0.90f, false);
    }

    bool Actions::Hello() const {
        return ClickInCenterIfVisible("actions/button_hello.png", 0.90f, false);
    }

    bool Actions::Applause() const {
        return ClickInCenterIfVisible("actions/button_applause.png", 0.90f, false);
    }
}
