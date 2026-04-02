#pragma once
#include "LibGame/Interactions.hpp"

#include <LibIO/clipboard/ClipboardControls.hpp>

#include <string>

using namespace LibIO::Clipboard;

namespace LibGame::Io {
    class Clipboard final : public BaseInteraction {
    public:
        explicit Clipboard(Interactions *core);
        ~Clipboard() override;

        void Copy(std::string text) const;
        std::string Paste() const;
        void Clear() const;

    private:
        ClipboardControls *Controller = nullptr;
    };
}
