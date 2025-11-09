#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Clipboard final : public BaseModule {
    public:
        explicit Clipboard(Interactions *core) : BaseModule(core) {};
        ~Clipboard() override = default;

        void Copy(const std::string& text);
        std::optional<std::string> Paste();
        void Clear();
    };
}
