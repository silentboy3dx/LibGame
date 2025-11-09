#include "LibGame/module/Clothing.hpp"

#include "LibGame/io/Mouse.hpp"
#include "LibGame/misc/Point.h"

using namespace LibGame::Detect;

namespace LibGame::Module {
    bool Clothing::isPanelOpen() const {
        return isVisible("clothing/header_appearance.png", 0.97f, false, true);
    }

    bool Clothing::OpenPanel() const {
        return ClickInCenterIfVisible("clothing/button_clothes.png", 0.98f, false);
    }

    bool Clothing::ClosePanel() const {
        if (isPanelOpen()) {
            const std::optional<DResult> result = detector->Single(
                assets->AssetFile("clothing/header_appearance.png"),
                DArgs{.confidence = 0.97f}
            );

            if (result) {
                const DResult headerBar = result.value();

                const auto position = Point(headerBar.X + headerBar.Width - 7, headerBar.Y + headerBar.Height / 2);

                mouse->MoveToAndClick(position.X, position.Y);
                return true;
            }
        }

        return false;
    }

    bool Clothing::IsWet() const {
        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_dry.png"),
            DArgs{.confidence = 0.97f}
        );

        return result.has_value();
    }

    bool Clothing::IsDry() const {
        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_wet.png"),
            DArgs{.confidence = 0.98f}
        );

        return result.has_value();
    }

    bool Clothing::PutAllOn() const {

        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        const bool result = ClickInCenterIfVisible("clothing/button_put_on_all.png", 0.98f, false);

        if (!ClosePanel()) {
            return false;
        }

        return result;
    }

    bool Clothing::TakeAllOff() const {

        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        const bool result = ClickInCenterIfVisible("clothing/button_put_off_all.png", 0.97f, false);

        if (!ClosePanel()) {
            return false;
        }

        return result;
    }

    bool Clothing::Wet() const {

        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        const bool result = ClickInCenterIfVisible("clothing/button_wet.png", 0.97f, false);

        if (!ClosePanel()) {
            return false;
        }

        return result;
    }

    bool Clothing::Dry() const {

        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        const bool result = ClickInCenterIfVisible("clothing/button_dry.png", 0.98f, false);

        if (!ClosePanel()) {
            return false;
        }

        return result;
    }

    bool Clothing::ToggleWetness() const {

        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        bool result = false;

        if (IsDry()) {

            result = Wet();
        } else {

            result = Dry();
        }

        if (result) {
            sleepms(300);
        }

        if (!ClosePanel()) {
            return false;
        }

        return result;
    }
}
