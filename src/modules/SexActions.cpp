#include "LibGame/module/SexActions.hpp"

namespace LibGame::Module {
    bool SexActions::Moan() const {
        return ClickIfVisible("sexactions/moan.png", 0.96f, true);
    }

    bool SexActions::Cum() const {
        return ClickIfVisible("sexactions/cum.png", 0.96f, true);
    }
}
