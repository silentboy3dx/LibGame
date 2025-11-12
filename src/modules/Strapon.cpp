#include "LibGame/module/Strapon.hpp"

#include "LibGame/action/secondary/StraponSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using namespace LibGame::Action::Secondary;

namespace LibGame::Module {
    bool Strapon::Off() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_off.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );

        if (result) {
            core->GetInteraction<Context>()
            .AddSecondaryAction<StraponSecondaryStatus>(StraponSecondaryStatus::Type::Off);
        }

        return result;
    }

    bool Strapon::Penis() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_penis.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );

        if (result) {
            core->GetInteraction<Context>()
            .AddSecondaryAction<StraponSecondaryStatus>(StraponSecondaryStatus::Type::Penis);
        }

        return result;
    }

    bool Strapon::Toy1() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_strapon_1.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );

        if (result) {
            core->GetInteraction<Context>()
                                .AddSecondaryAction<StraponSecondaryStatus>(StraponSecondaryStatus::Type::Toy1);
        }

        return result;
    }

    bool Strapon::Toy2() const {
        const auto result = ClickIfFirstAssetIsVisible(
            "strapon/strapon_panel_header.png",
            "strapon/button_strapon_2.png",
            DArgs{.confidence = 0.99f},
            DArgs{.confidence = 0.99f}
        );

        if (result) {
            core->GetInteraction<Context>()
                    .AddSecondaryAction<StraponSecondaryStatus>(StraponSecondaryStatus::Type::Toy2);
        }

        return result;
    }
}
