#include "LibGame/Interactions.hpp"
#include <LibOs/LibOS.hpp>

namespace LibGame {
    Interactions *Interactions::_instance = nullptr;


    bool Interactions::IsGameInForeground() {
        if (OperatingSystem.IsWindows()) {
            return IO.Os.Windows.IsWindowFocused("3DXChat");
        }

        return OperatingSystem.IsLinux() && Linux.IsWindowFocused("3DXChat");
    }
}
