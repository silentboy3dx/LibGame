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
            {1, 1.5f}, {2, 1.5f}, {3, 1.5f}, {4, 1.5f},
            {5, 1.5f}, {6, 1.5f}, {7, 1.5f}, {8, 1.5f},
            {9, 1.5f}, {10, 1.5f}, {11, 1.5f}, {12, 1.5f},
            {13, 1.5f}, {14, 1.5f}, {15, 1.5f}, {16, 1.5f},
            {17, 1.5f}, {18, 1.5f}, {19, 1.5f}, {20, 1.5f},
            {21, 1.5f}, {22, 1.5f}, {23, 1.5f}, {24, 1.5f},
            {25, 1.5f}, {26, 1.5f}, {27, 1.5f}, {28, 1.5f},
            {29, 1.5f}, {30, 1.5f}, {31, 1.5f}, {32, 1.5f},
            {33, 1.5f}, {34, 1.5f}, {35, 1.5f}, {36, 1.5f},
            {37, 1.5f}, {38, 1.5f}, {39, 1.5f}, {40, 1.5f},
            {41, 1.5f}, {42, 1.5f}, {43, 1.5f}, {44, 1.5f},
            {45, 1.5f}, {46, 1.5f}, {47, 1.5f}
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
