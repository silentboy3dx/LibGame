#include "LibGame/module/Clothing.hpp"

#include "LibGame/io/Mouse.hpp"
#include "LibGame/misc/Point.h"

#include <iostream>


namespace LibGame::Module {
    bool Clothing::isPanelOpen() const {
        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/header_appearance.png"),
            DArgs{.confidence = 0.97f}
        );

        return result.has_value();
    }

    void Clothing::OpenPanel() const {
        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_clothes.png"),
            DArgs{.confidence = 0.98f}
        );

        if (result) {
            mouse->MoveToAndClick(result->X, result->Y);
            std::cout << "Found clothing clicking on X: " << result->X << " Y: " << result->Y << std::endl;

            sleepms(300);
        } else {
            std::cout << "Didn't find clothing" << std::endl;
        }
    }

    void Clothing::ClosePanel() const {
        if (isPanelOpen()) {
            const std::optional<DResult> result = detector->Single(
                assets->AssetFile("clothing/header_appearance.png"),
                DArgs{.confidence = 0.97f}
            );

            if (!result) return;
            const DResult headerBar = result.value();

            const auto position = Point(headerBar.X + headerBar.Width - 7, headerBar.Y + headerBar.Height / 2);

            mouse->MoveToAndClick(position.X, position.Y);
        }
    }

    bool Clothing::IsWet() const {
        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_dry.png"),
            DArgs{.confidence = 0.98f}
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

    void Clothing::PutAllOn() const {
        if (isPanelOpen()) {
            OpenPanel();
        }

        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_put_on_all.png"),
            DArgs{.confidence = 0.97f}
        );

        if (result) {
            const DResult button = result.value();
            const auto center = button.Center();

            // Core?.GetInteraction<Context>()
            //     .SetSecondaryAction<NakedSecondaryStatus, NakedSecondaryStatus.Type>(NakedSecondaryStatus.Type.Dressed);
            //


            mouse->MoveToAndClick(center.X, center.Y);
            sleepms(300);
        }

        ClosePanel();
    }

    void Clothing::TakeAllOff() const {
        OpenPanel();

        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_put_off_all.png"),
            DArgs{.confidence = 0.97f}
        );

        if (result) {
            const DResult button = result.value();
            const auto center = button.Center();

            mouse->MoveToAndClick(center.X, center.Y);
        }

        ClosePanel();
    }

    void Clothing::Wet() const {
        OpenPanel();

        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_wet.png"),
            DArgs{.confidence = 0.98f}
        );

        if (result) {
            const DResult button = result.value();
            const auto center = button.Center();

            mouse->MoveToAndClick(center.X, center.Y);
        }


        ClosePanel();
    }

    void Clothing::Dry() const {
        OpenPanel();

        const std::optional<DResult> result = detector->Single(
            assets->AssetFile("clothing/button_dry.png"),
            DArgs{.confidence = 0.98f}
        );

        if (result) {
            const DResult button = result.value();
            const auto center = button.Center();

            mouse->MoveToAndClick(center.X, center.Y);
        }

        ClosePanel();
    }

    void Clothing::ToggleWetness() const {
        OpenPanel();

        if (IsDry()) {
            const std::optional<DResult> result = detector->Single(
                assets->AssetFile("clothing/button_wet.png"),
                DArgs{.confidence = 0.97f}
            );

            if (result) {
                const DResult button = result.value();
                const auto center = button.Center();

                mouse->MoveToAndClick(center.X, center.Y);
                sleepms(300);
            }
        } else {

            const std::optional<DResult> result = detector->Single(
                assets->AssetFile("clothing/button_dry.png"),
                DArgs{.confidence = 0.98f}
            );

            if (result) {
                const DResult button = result.value();
                const auto center = button.Center();

                mouse->MoveToAndClick(center.X, center.Y);
                sleepms(300);
            }
        }

        ClosePanel();
    }
}
