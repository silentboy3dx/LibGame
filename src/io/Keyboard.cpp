#include "LibGame/io/Keyboard.hpp"

#include <LibIO/LibIO.hpp>
#include <chrono>
#include <thread>

using namespace LibIO;
using namespace std::this_thread;

namespace LibGame::Io {

    Keyboard::Keyboard(Interactions *core) : core(core) {
        Controller = GetKeyboardControls();
    }

    Keyboard::~Keyboard() {
        delete Controller;
    }

    void Keyboard::Press(const char key) const {
        Press(std::string(1, key));
    }

    void Keyboard::Press(const std::string& key) const {
        Controller->PressKey(key);
    }

    void Keyboard::Hotkey(const std::string& modifier, const std::string& key) const {
        Controller->Hotkey(modifier, key);
    }

    void Keyboard::Typewrite(const std::string& text, const int interval) const {
        for (const char c : text) {
            Press(c);

            sleep_for(std::chrono::milliseconds(interval));
        }
    }

    void Keyboard::Write(const std::string& text) const {
        for (const char c : text) {
            Press(c);
        }
    }
}