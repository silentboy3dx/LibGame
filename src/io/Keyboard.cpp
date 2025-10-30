#include "LibGame/io/Keyboard.hpp"

#include <LibIO/LibIO.hpp>

using namespace LibIO;

namespace LibGame::Io {

    Keyboard::Keyboard() {
        Controller = GetKeyboardControls();
    }

    Keyboard::~Keyboard() {
        delete Controller;
    }

    void Keyboard::Press(std::string key) {
    }

    void Keyboard::Hotkey(std::string modifier, std::string key) {
    }

    void Keyboard::Typewrite(std::string text, int interval) {
    }

    void Keyboard::Write(std::string text) {
    }
}