#include "LibGame/io/Clipboard.hpp"

#include <LibIO/LibIO.hpp>
#include <utility>

using namespace LibIO;
using LibIO::GetClipboardControls;

namespace LibGame::Io {

    Clipboard::Clipboard(Interactions *core) : BaseInteraction(core){
        Controller = GetClipboardControls();
    }

    Clipboard::~Clipboard() {
        delete Controller;
    }

    void Clipboard::Copy(std::string text) const {
        return Controller->Copy(std::move(text));
    }

    std::string Clipboard::Paste() const {
        return Controller->Paste();
    }

    void Clipboard::Clear() const {
        return Controller->Clear();
    }
}
