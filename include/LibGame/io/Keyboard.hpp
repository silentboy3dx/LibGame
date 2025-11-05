#pragma once
#include "LibGame/Interactions.hpp"

#include <LibIO/keyboard/KeyboardControls.hpp>
#include <string>


using namespace LibIO::Keyboard;

namespace LibGame::Io {
    class Keyboard : public BaseInteraction {
    public:
        explicit Keyboard(Interactions *core);

        ~Keyboard() override;

        void Press(char key) const;

        void Press(const std::string &key) const;

        void Hotkey(const std::string &modifier, const std::string &key) const;

        void Typewrite(const std::string &text, int interval = 100) const;

        void Write(const std::string &text) const;

    private:
        KeyboardControls *Controller = nullptr;
    };
}
