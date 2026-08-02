#include "LibGame/io/Clipboard.hpp"

#include <LibIO/LibIO.hpp>
#include <utility>

using namespace LibIO;
using LibIO::GetClipboardControls;

namespace LibGame::Io {

    Clipboard::Clipboard(Interactions *core) : BaseInteraction(core), Controller(GetClipboardControls()) {
    }

    void Clipboard::Copy(std::string text) {
        return Controller->Copy(std::move(text));
    }

    std::string Clipboard::Paste() {
        return Controller->Paste();
    }

    void Clipboard::Clear() {
        return Controller->Clear();
    }

    bool Clipboard::CopyAndConfirm(const std::string &text, const std::chrono::milliseconds timeout) {
        return Controller->CopyAndConfirm(text, timeout);
    }

    std::string Clipboard::WaitForChange(const std::string &previous, const std::chrono::milliseconds timeout) {
        return Controller->WaitForChange(previous, timeout);
    }
}
