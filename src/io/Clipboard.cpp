#include "LibGame/io/Clipboard.hpp"

#include <LibIO/LibIO.hpp>
#include <utility>

using namespace LibIO;
using LibIO::GetClipboardControls;

namespace LibGame::Io {

    Clipboard::Clipboard(Interactions *core) : BaseInteraction(core){
        // Empty for now
    }

    void Clipboard::Copy(std::string text) {
        return GetClipboardControls()->Copy(std::move(text));
    }

    std::string Clipboard::Paste() {
        return GetClipboardControls()->Paste();
    }

    void Clipboard::Clear() {
        return GetClipboardControls()->Clear();
    }
}
