#include "LibGame/Interactions.hpp"

#include <iostream>
#include <optional>
#include <LibOS/LibOS.hpp>

using namespace LibOS;

namespace LibGame {
    Interactions *Interactions::_instance = nullptr;


    bool Interactions::IsGameInForeground() {

        std::optional<WindowInfo> info = GetActiveWindow();

        if (info) {
            return info->title == "3DXChat";
        }

        return false;
    }
}