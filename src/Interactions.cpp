#include "LibGame/Interactions.hpp"

#include "LibGame/io/Mouse.hpp"
#include "LibGame/io/Keyboard.hpp"

#include "LibGame/module/Clothing.hpp"
#include "LibGame/module/Clothing.hpp"

#include <LibOS/LibOS.hpp>
#include <optional>

#include "LibGame/io/Screenshot.hpp"

using namespace LibOS;
using namespace LibGame::Module;
using namespace LibGame::Io;

namespace LibGame {
    Interactions *Interactions::_instance = nullptr;

    Interactions::Interactions() {
        RegisterInteraction<Mouse>();
        RegisterInteraction<Keyboard>();
        RegisterInteraction<Screenshot>();
        RegisterInteraction<Detector>();
        RegisterInteraction<Assets>();

        RegisterModule<Clothing>();
    }

    Interactions &Interactions::GetInstance(){
        if (_instance == nullptr) {
            _instance = new Interactions();
        }
        return *_instance;
    }

    bool Interactions::IsGameInForeground() {
        if (const std::optional<WindowInfo> info = GetActiveWindow()) {
            return info->title == "3DXChat";
        }

        return false;
    }
}

