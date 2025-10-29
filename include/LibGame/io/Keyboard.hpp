#pragma once
#include "LibIO/keyboard/KeyboardControls.hpp"

#include <string>

using namespace LibIO::Keyboard;

namespace LibGame::Io {
    class Keyboard {
        Keyboard();

        ~Keyboard();

        void Press(std::string key);

        void Hotkey(std::string modifier, std::string key);

        void Typewrite(std::string text, int interval = 0);

        void Write(std::string text);

    private:
        KeyboardControls *Controller = nullptr;
    };
}
