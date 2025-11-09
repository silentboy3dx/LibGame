#include "LibGame/module/Dances.hpp"

#include "LibGame/module/BaseModule.hpp"

namespace LibGame::Module {
    std::unordered_map<int, float> Dances::_confidences;
    std::unordered_map<int, Image> Dances::_assets;

    Dances::Dances(Interactions *core) : BaseModule(core) {

        _confidences = {
            {1, 0.97f},
            {2, 0.91f},
            {3, 0.93f},
            {4, 0.93f},
            {5, 0.93f},
            {6, 0.66f},
            {7, 0.95f},
            {8, 0.94f},
            {9, 0.94f},
            {10, 0.96f},
            {11, 0.96f},
            {12, 0.92f},
            {13, 0.94f},
            {14, 0.95f},
            {15, 0.94f},
            {16, 0.95f},
            {17, 0.94f},
            {18, 0.94f},
            {19, 0.94f},
            {20, 0.90f},
            {21, 0.88f},
            {22, 0.90f},
            {23, 0.91f},
            {24, 0.91f},
            {25, 0.91f},
            {26, 0.92f},
            {27, 0.92f},
            {28, 0.92f},
            {29, 0.91f},
            {30, 0.92f},
            {31, 0.94f},
            {32, 0.91f},
            {33, 0.92f},
            {34, 0.93f},
            {35, 0.92f},
            {36, 0.93f},
            {37, 0.93f},
            {38, 0.9333368f},
            {39, 0.93f},
            {40, 0.94f},
            {41, 0.95f},
            {42, 0.91f},
            {43, 0.93f},
            {44, 0.93f},
            {45, 0.93f},
            {46, 0.93f},
            {47, 0.94f}
        };

        InitAssets();
    }

    void Dances::InitAssets() const {

        for (int num = 47; num > 0; num--)
        {
            _assets[num] = assets->AssetFile(std::format("dances/{}.png", num));
        }
    }

    void Dances::ScrollToTop() const {

        const int x = _header.X + headerWidth - (scrollbarWidth / 2);
        const int y = _header.Y + headerHeight;

        mouse->MoveTo(x, y);

        for (int step = 0; step < 7; step++)
        {
            mouse->ScrollUp();
        }

        sleepms(100);
    }

    std::optional<DResult> Dances::GetDanceHeader() const {
        return detector->Single(
                assets->AssetFile("dances/dance_panel_header.png"),
                DArgs{.cacheable = true, .grayscale = true, .confidence = 0.95f}
            );
    }

    std::optional<DResult> Dances::GetDanceLocation(int dance) const {

        if (const auto shot = screenshots->Take(); shot.image.isValid()) {

            /**
             * This will cut out only
             * the buttons.
             */
            const int x = _header.X;
            const int y = _header.Y;

            const Image crop = shot.image.crop(
               x,
               y,
               dancesInnerWidth,
               dancesInnerHeight
            );

            if (crop.isValid()) {
                return detector->Single(
                    assets->AssetFile(std::format("dances/{}.png", dance)),
                    DArgs{.grayscale = true, .confidence = _confidences[dance], .match_target = crop}
                );
            }
        }

        return std::nullopt;
    }

    std::optional<DResult> Dances::FindDance(const int dance) const {

        int attempt = 0;
        int amount = 0;
        while (attempt <= 10) {

            if (auto result = GetDanceLocation(dance); result.has_value())
            {
                return result.value();
            }

            const int x = (_header.X - cornerOffset) + headerWidth - (scrollbarWidth / 2);
            const int y = _header.Y + headerHeight;

            mouse->MoveTo(x, y);
            mouse->ScrollDown();

            attempt += 1;
            amount += 1;
        }

        return std::nullopt;
    }


    bool Dances::Dance(const int number) {

        InitAssets();

        if (auto result = GetDanceHeader(); result.has_value()) {
            _header = result.value();
            _header.X -= cornerOffset;

            ScrollToTop();

            result = FindDance(number);

            if (result) {
                const DResult button = result.value();
                const auto center = button.Center();

                mouse->MoveToAndClick(_header.X + center.X, _header.Y  + center.Y);
                return true;
            }
        }

        return false;
    }
}