#pragma once

#include <X11/Xlib.h>

#include "LibGame/Interactions.hpp"
#include "LibGame/detect/Detector.hpp"
#include "LibGame/asset/Assets.hpp"

#include "LibGame/io/Keyboard.hpp"
#include "LibGame/io/Mouse.hpp"
#include "LibGame/io/Screenshot.hpp"

#include <thread>
#include <chrono>
#include <iostream>

using namespace LibGame::Io;
using namespace LibGame::Detect;
using namespace LibGame::Asset;

namespace LibGame::Module {
    class BaseModule : public BaseInteraction {
    public:
        explicit BaseModule(Interactions *core) : BaseInteraction(core) {
            screenshots = core ? &core->GetInteraction<Screenshot>() : nullptr;
            keyboard = core ? &core->GetInteraction<Keyboard>() : nullptr;
            mouse = core ? &core->GetInteraction<Mouse>() : nullptr;

            detector = core ? &core->GetInteraction<Detector>() : nullptr;
            assets = core ? &core->GetInteraction<Assets>() : nullptr;
        }

        ~BaseModule() override = default;

    protected:
        Assets *assets = nullptr;
        Detector *detector = nullptr;
        Keyboard *keyboard = nullptr;
        Screenshot *screenshots = nullptr;
        Mouse *mouse = nullptr;

        [[nodiscard]] std::optional<DResult> GetAsset(const std::string& asset, const DArgs &args = DArgs{.grayscale = false, .confidence = 0.99f}) const {
            return detector->Single(
                           assets->AssetFile(asset),
                           args
                       );
        }

        [[nodiscard]] bool isVisible(const std::string &asset, const float confidence = 0.98f, const bool grayscale = false, const bool cachable = false) const {
            const std::optional<DResult> result = detector->Single(
                assets->AssetFile(asset),
                DArgs{.cacheable = cachable, .grayscale = grayscale, .confidence = confidence}
            );

            return result.has_value();
        }

        [[nodiscard]] bool ClickIfVisible(const std::string &asset, const float confidence = 0.98f, const bool grayscale = false, const bool cachable = false) const {
            const std::optional<DResult> result = detector->Single(
                assets->AssetFile(asset),
                DArgs{.cacheable = cachable, .grayscale = grayscale, .confidence = confidence}
            );

            if (result) {
                const DResult button = result.value();
                const auto center = button.Center();

                mouse->MoveToAndClick(center.X, center.Y);

                sleepms(300);
                return true;
            } else {
                std::cout << "Could not find " << asset << std::endl;
            }

            return false;
        }

        [[nodiscard]] bool ClicIfFirstAssetIsVisible(const std::string &primary_asset, const std::string &secondary_asset, const DArgs &primary_args, const DArgs &secondary_args) const {

            const std::optional<DResult> primary_result = detector->Single(
                            assets->AssetFile(primary_asset),
                            primary_args
                        );


            if (primary_result) {


                DArgs recreated_args = secondary_args;
                recreated_args.match_target = core->GetInteraction<Detector>().GetLastTarget();


                const std::optional<DResult> secondary_result = detector->Single(
                            assets->AssetFile(secondary_asset),
                            recreated_args
                        );

                if (secondary_result) {
                    const DResult button = secondary_result.value();
                    const auto center = button.Center();

                    mouse->MoveToAndClick(center.X, center.Y);
                    return true;
                }
            }

            return false;
        }


        static void sleepms(const int ms) {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
    };
}
