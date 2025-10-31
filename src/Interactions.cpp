#include "LibGame/Interactions.hpp"

#include <iostream>
#include <optional>
#include <LibOS/LibOS.hpp>

using namespace LibOS;

namespace LibGame {
    Interactions *Interactions::_instance = nullptr;

    bool Interactions::IsGameInForeground() {
        if (const std::optional<WindowInfo> info = GetActiveWindow()) {
            return info->title == "3DXChat";
        }

        return false;
    }
}
