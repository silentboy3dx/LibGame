#pragma once

#include <optional>

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Chat final : public BaseModule {
    public:
        explicit Chat(Interactions *core) : BaseModule(core) {};

        ~Chat() override = default;

        [[nodiscard]] std::optional<DResult> GetLocalTab() const;

        [[nodiscard]] bool PlaceCursorInChat() const;
        [[nodiscard]] bool GoToLocal() const;
        [[nodiscard]] bool PressSend() const;
        void WipeChat() const;
    };
}