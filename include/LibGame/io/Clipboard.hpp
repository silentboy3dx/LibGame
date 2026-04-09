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

        static void Copy(std::string text) ;
        static [[nodiscard]] std::string Paste() ;
        static void Clear() ;

    private:
        ClipboardControls *Controller = nullptr;
    };
}
