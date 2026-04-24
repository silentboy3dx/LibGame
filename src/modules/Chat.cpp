#include "LibGame/module/Chat.hpp"

namespace LibGame::Module {
    std::optional<DResult> Chat::GetLocalTab() const {
        auto screenshot = detector->GetLastTarget();

        if (!screenshot.isValid()) {
            if (const auto result = core->GetInteraction<Screenshot>().Take(); result.isValid()) {
                detector->SetLastTarget(result);

                screenshot = result;
            }
        }

        auto args = DArgs(0.97f);
        args.match_target = screenshot;

        const std::optional<DResult> highlighted = detector->Single(
            assets->AssetFile("chat/tab_local_highlighted.png"),
            args
        );

        if (highlighted) return highlighted;

        args = DArgs(0.92f);
        args.match_target = screenshot;

        const std::optional<DResult> unselected = detector->Single(
            assets->AssetFile("chat/tab_local_unselected.png"),
            args
        );

        if (unselected) return unselected;

        return std::nullopt;
    }

    bool Chat::GoToLocal() const {
        if (const auto tab = GetLocalTab(); tab.has_value()) {
            const DResult button = tab.value();
            const auto result = button.Center();

            mouse->MoveToAndClick(result.X, result.Y);
            return true;
        }

        return false;
    }

    bool Chat::PlaceCursorInChat() const {


        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("chat/button_send.png"),
            DArgs(0.99f, true)
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
        return ClickIfVisible("chat/button_send.png", 0.99f, true);
    }

    void Chat::WipeChat() const {
        if (PlaceCursorInChat()) {
#if PLATFORM_LINUX
            sleepms(200);
#endif

            keyboard->Hotkey("ctrl", "a");
            keyboard->Press("backspace");
        }
    }
}
