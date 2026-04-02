#pragma once

#include "BaseModule.hpp"

#include <optional>

namespace LibGame::Module {
    class Profile final : public BaseModule {
    public:
        explicit Profile(Interactions *core) : BaseModule(core) {
        };

        ~Profile() override = default;

        bool IsMyProfileOpen() const;
        bool IsOthersProfileOpen() const;

        bool OpenMyProfile() const;
        bool CloseMyProfile() const;
        bool CloseProfile() const;

    private:
        const int profileWidth = 678;
        const int closeBtnWidth = 28;
        const int closeBtnHeight = 28;
        std::optional<DResult> GetMyProfileLabel() const;
    };
}
