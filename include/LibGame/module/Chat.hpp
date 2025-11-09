#pragma once

#include <absl/types/optional.h>

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Chat final : public BaseModule {
    public:
        explicit Chat(Interactions *core) : BaseModule(core) {};

        ~Chat() override = default;

        bool PlaceCursorInChat() const;
        bool GoToLocal() const;
        bool PressSend() const;
        bool WhipeChat() const;

    private:
        std::optional<DResult> GetLocalTab() const;

    };
}