#include "LibGame/module/Dances.hpp"

#include "LibGame/statuses/primary/DanceStatus.hpp"
#include "LibGame/module/BaseModule.hpp"
#include "LibGame/module/Context.hpp"

using namespace LibGame::Statuses::Primary;

namespace LibGame::Module {

    std::unordered_map<int, float> Dances::_confidences;
    std::unordered_map<int, Image> Dances::_assets;
    bool Dances::_assetsInitialized = false;

    Dances::Dances(Interactions *core)
        : BaseModule(core)
    {
        _confidences = {
            {1, 0.97f}, {2, 0.98f}, {3, 0.98f}, {4, 0.99f},
            {5, 0.97f}, {6, 0.98f}, {7, 0.97f}, {8, 1.0f},
            {9, 0.98f}, {10, 0.98f}, {11, 0.98f}, {12, 0.93f},
            {13, 0.98f}, {14, 0.98f}, {15, 0.98f}, {16, 0.98f},
            {17, 0.98f}, {18, 0.98f}, {19, 0.98f}, {20, 0.98f},
            {21, 0.98f}, {22, 0.98f}, {23, 0.98f}, {24, 0.98f},
            {25, 0.97f}, {26, 0.98f}, {27, 0.98f}, {28, 0.98f},
            {29, 0.97f}, {30, 0.98f}, {31, 0.98f}, {32, 0.98f},
            {33, 0.97f}, {34, 0.98f}, {35, 0.98f}, {36, 0.98f},
            {37, 0.97f}, {38, 0.98f}, {39, 0.98f}, {40, 0.98f},
            {41, 0.98f}, {42, 0.98f}, {43, 0.98f}, {44, 0.95f},
            {45, 0.97f}, {46, 0.98f}, {47, 0.98f}
        };

        // ⚠️ Belangrijk:
        // InitAssets() wordt NIET in de constructor aangeroepen,
        // omdat BaseModule::assets nog niet bestaat tijdens constructie.
    }

    void Dances::InitAssets() const {

        if (_assetsInitialized)
            return;

        for (int num = 47; num > 0; num--) {
            _assets[num] = assets->AssetFile(std::format("dances/{}.png", num));
        }

        _assetsInitialized = true;
    }

    void Dances::ScrollToTop() const {

        const int x = _header.X + headerWidth - (scrollbarWidth / 2);
        const int y = _header.Y + headerHeight;

        mouse->MoveTo(x, y);

        for (int step = 0; step < 7; step++) {
            mouse->ScrollUp();
        }

        sleepms(900);
    }

    std::optional<DResult> Dances::GetDanceHeader() const {
        return detector->Single(
            assets->AssetFile("dances/dance_panel_header.png"),
            DArgs(0.94f, true, true, true)
        );
    }

    std::optional<DResult> Dances::GetDanceLocation(int dance) const {

        if (const auto shot = screenshots->Take(); shot.isValid()) {

            const int x = _header.X;
            const int y = _header.Y;

            const Image crop = shot.crop(
                x,
                y,
                dancesInnerWidth + 4,
                dancesInnerHeight
            );

            if (crop.isValid()) {
                auto args = DArgs(_confidences[dance], true, false, true);
                args.match_target = crop;

                return detector->Single(
                    assets->AssetFile(std::format("dances/{}.png", dance)),
                    args
                );
            }
        }

        return std::nullopt;
    }

    std::optional<DResult> Dances::FindDance(const int dance) const {

        int attempt = 0;
        int amount = 0;

        while (attempt <= 10) {

            if (auto result = GetDanceLocation(dance); result.has_value()) {
                return result.value();
            }

            const int x = (_header.X - cornerOffset) + headerWidth - (scrollbarWidth / 2);
            const int y = _header.Y + headerHeight;

            mouse->MoveTo(x, y);
            mouse->ScrollDown();

            sleepms(300);

            attempt += 1;
            amount += 1;
        }

        return std::nullopt;
    }

    bool Dances::Dance(const int number) {

        InitAssets();
        InitAssets();

        if (auto result = GetDanceHeader(); result.has_value()) {

            _header = result.value();
            _header.X -= cornerOffset;

            ScrollToTop();

            result = FindDance(number);

            if (result) {
                const DResult button = result.value();
                const auto center = button.Center();

                mouse->MoveToAndClick(_header.X + center.X, _header.Y + center.Y);

                core->GetInteraction<Context>()
                    .SetPrimaryStatus<DanceStatus>(DanceStatus::DanceTypeFromInt(number));

                return true;
            }
        } else {
            std::cerr << "Failed to find dance header" << std::endl;
        }

        return false;
    }
}
