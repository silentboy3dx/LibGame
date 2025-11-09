#include "LibGame/module/Clipboard.hpp"

namespace LibGame::Module {
    void Clipboard::Copy(const std::string& text) {
        throw std::runtime_error("Not implemented");
    }

    std::optional<std::string> Clipboard::Paste() {
        throw std::runtime_error("Not implemented");
    }

    void Clipboard::Clear() {
        throw std::runtime_error("Not implemented");
    }
}
