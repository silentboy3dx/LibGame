#pragma once
#include "LibGame/Interactions.hpp"

#include <LibIO/clipboard/ClipboardControls.hpp>

#include <string>

using namespace LibIO::Clipboard;

namespace LibGame::Io {
    class Clipboard final : public BaseInteraction {
    public:
        explicit Clipboard(Interactions *core);
        ~Clipboard() override = default;

        void Copy(std::string text) ;
        std::string Paste();
        void Clear() ;

    private:
        ClipboardControls *Controller = nullptr;
    };
}
