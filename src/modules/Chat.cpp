#include "LibGame/module/Chat.hpp"

namespace LibGame::Module {
    std::optional<DResult> Chat::GetLocalTab() const {

        auto screenshot = detector->GetLastTarget();

        if (!screenshot.isValid()) {
            if (const auto result = core->GetInteraction<Screenshot>().Take(); result.image.isValid()) {
                detector->SetLastTarget(result.image);

                screenshot = result.image;
            }
        }

        const std::optional<DResult> highlighted = detector->Single(
            assets->AssetFile("chat/tab_local_highlighted.png"),
            DArgs{.confidence = 0.97f, .match_target = screenshot}
        );

        if (highlighted) return highlighted;

        const std::optional<DResult> unselected = detector->Single(
            assets->AssetFile("chat/tab_local_unselected.png"),
            DArgs{.confidence = 0.92f, .match_target = screenshot}
        );

        if (unselected) return unselected;

        const std::optional<DResult> selected = detector->Single(
            assets->AssetFile("chat/tab_local_unselected.png"),
            DArgs{.confidence = 0.92f, .match_target = screenshot}
        );

        return selected;
    }

    bool Chat::GoToLocal() const {
        if (const auto tab = GetLocalTab(); tab.has_value()) {
            const DResult button = tab.value();
            const auto result = button.Center();

            mouse->MoveToAndClick(result.X, result.Y);
            return true;
        } else {
            std::cout << "Could not find local tab" << std::endl;
        }

        return false;
    }

    bool Chat::PlaceCursorInChat() const {

        const std::optional<DResult> result = detector->Single(
               assets->AssetFile("chat/button_send.png"),
               DArgs{.confidence = 0.99f}
           );

        if (result) {
            const DResult clickLoc = result.value();
            constexpr int btnWidth = 100;

            mouse->MoveToAndClick(clickLoc.X - btnWidth, clickLoc.Y);
            return true;
        }

        return false;
    }

    bool Chat::PressSend() const {
        return ClickIfVisible("chat/button_send.png", 0.99f, false);
    }

    bool Chat::WipeChat() const {
        if (PlaceCursorInChat()) {

#if PLATFORM_LINUX
            sleepms(200);
#endif

            keyboard->Hotkey("ctrl", "a");
            keyboard->Press("backspace");

            return true;
        }

        return false;
    }
}
