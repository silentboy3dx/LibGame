#pragma once

#include "LibGame/Interactions.hpp"

#include <LibIO/keyboard/KeyboardControls.hpp>
#include <string>

using namespace LibIO::Keyboard;

namespace LibGame::Io {
    class Keyboard : public BaseInteraction {
    public:
        explicit Keyboard(Interactions *core);

        ~Keyboard() override = default;

        static void Press(char key) ;

        static void Press(const std::string &key) ;

        static void Hotkey(const std::string &modifier, const std::string &key) ;

        static void Typewrite(const std::string &text, int interval = 100) ;

        static void Write(const std::string &text) ;
    };
}
