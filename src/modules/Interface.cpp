#include "LibGame/module/Interface.hpp"

namespace LibGame::Module {
    void Interface::HideInterface() const {
        keyboard->Hotkey("shift", "z");
    }

    void Interface::ShowInterface() const {
        keyboard->Hotkey("shift", "z");
    }
}
