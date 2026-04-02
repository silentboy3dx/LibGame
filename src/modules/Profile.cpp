#include "LibGame/module/Profile.hpp"

namespace LibGame::Module {
    std::optional<DResult> Profile::GetMyProfileLabel() const {
        return detector->Single(
            assets->AssetFile("profile/label_my_profile.png"),
            DArgs{.confidence = 0.99f}
        );
    }

    bool Profile::IsMyProfileOpen() const {
        return (GetMyProfileLabel().has_value() && !IsOthersProfileOpen());
    }

    bool Profile::IsOthersProfileOpen() const {
        return (detector->Single(
                    assets->AssetFile("profile/button_more.png"),
                    DArgs{.confidence = 0.99f}
                ) != std::nullopt);
    }

    bool Profile::OpenMyProfile() const {
        return ClickIfVisible("profile/button_profile.png", 0.99f, false);
    }

    bool Profile::CloseMyProfile() const {
        return ClickIfVisible("profile/button_profile.png", 0.99f, false);
    }

    bool Profile::CloseProfile() const {
        if (const auto result = GetMyProfileLabel()) {
            const DResult label = result.value();
            constexpr int cornerOffset = 10;

            const int x = (label.X - cornerOffset) + (profileWidth - closeBtnWidth/2);
            const int y = (label.Y + closeBtnHeight /2);

            mouse->MoveToAndClick(x, y);

            return true;
        }
        return false;
    }
}
