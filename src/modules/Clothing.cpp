#include "LibGame/module/Clothing.hpp"

#include "LibGame/action/secondary/NakedSecondaryStatus.hpp"
#include "LibGame/io/Mouse.hpp"
#include "LibGame/misc/Point.hpp"
#include "LibGame/module/Context.hpp"

#include <optional>

using LibGame::Action::Secondary::NakedSecondaryStatus;
using namespace LibGame::Detect;
using namespace LibGame::Misc;

namespace LibGame::Module {
    bool Clothing::isPanelOpen() const {
        return isVisible("clothing/header_appearance.png", 0.97f, false, true);
    }

    bool Clothing::OpenPanel() const {
        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_clothes.png"),
            DArgs{.confidence = 0.98f, .match_target = detector->GetLastTarget()}
        );

        if (result) {
            const DResult button = result.value();
            const auto center = button.Center();

            mouse->MoveToAndClick(center.X, center.Y);

            sleepms(300);
            return true;
        }

        return false;
    }

    bool Clothing::ClosePanel() const {
        if (isPanelOpen()) {
            const std::optional<DResult> result = detector->Single(
                assets->AssetFile("clothing/header_appearance.png"),
                DArgs{.confidence = 0.97f, .match_target = detector->GetLastTarget()}
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

    bool Clothing::DressAll() const {
        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        const bool result = ClickIfVisible("clothing/button_put_on_all.png", 0.98f, false);

        if (result) {
            core->GetInteraction<Context>().AddSecondaryAction<NakedSecondaryStatus>(
                NakedSecondaryStatus::Type::Dressed
            );
        }

        if (!ClosePanel()) {
            return false;
        }

        return result;
    }

    bool Clothing::UnDressAll() const {
        if (!isPanelOpen()) {
            if (!OpenPanel()) {
                return false;
            }
        }

        const bool result = ClickIfVisible("clothing/button_put_off_all.png", 0.97f, false);

        if (result) {
            core->GetInteraction<Context>().AddSecondaryAction<NakedSecondaryStatus>(
                NakedSecondaryStatus::Type::Undressed
            );
        }


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

        const bool result = ClickIfVisible("clothing/button_wet.png", 0.97f, false);

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

        const bool result = ClickIfVisible("clothing/button_dry.png", 0.98f, false);

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
