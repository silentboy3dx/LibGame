#include "LibGame/detect/Detector.hpp"

#include <iostream>

#include "LibGame/Interactions.hpp"

#include <LibGame/detect/DResult.hpp>

#include <LibGraphics/match/TemplateMatcher.hpp>
#include <LibGraphics/match/MatchOptions.hpp>

#include "LibScreenshots.hpp"
#include "LibGraphics/match/Region.hpp"

using namespace LibGraphics::Match;
using namespace LibScreenshots;

namespace LibGame::Detect {
    Detector::Detector(Interactions *core) : BaseInteraction(core) {
        matcher = TemplateMatcher();
    }
    void Detector::SetLastTarget(const Image &target) {
        lastTarget = target;
    }

    Image Detector::GetLastTarget() const {
        return lastTarget;
    }

    std::optional<DResult> Detector::Single(Image &match_template, const DArgs &args) {
        try {
            auto options = MatchOptions();
            std::optional<Image> match_target = args.match_target; // target is where to search in
            // Image match_template = args.match_template; // template is what we search
            bool toRealworld = false;

            if (args.cacheable) {
#pragma warning("Cache not implemented yet")
            }

            if (!match_target) {
                /**
                 * I could have made a crop from the screenshot (Image suports cropping) but i have chosen to
                 * screenshot a region of the screen instead for performance reasons.
                 */
                const ScreenshotResult screenshot = [&]() -> ScreenshotResult {
                    if (args.region.has_value()) {
                        return TakeScreenshot(args.region->X,
                                              args.region->Y,
                                              args.region->Width,
                                              args.region->Height);
                    } else {
                        return TakeScreenshot();
                    }
                }();

                match_target = screenshot.image;
            }

            if (args.region.has_value()) {
                toRealworld = true;
            }

            if (args.grayscale) {
                match_target = match_target->toGrayscale();
                match_template = match_template.toGrayscale();
            }

            // TODO: Add debug

            // TODO: Test grayscale by writing an image to disk
            // TODO: Implement caching mechanism
            // TODO: Test Region to realworld
            // TODO: Test Region
            // TODO: Test Debug

            options.minConfidence = args.confidence;

            SetLastTarget(match_target.value());

            // match_template.show();

            /**
             * We search for template in target.
             */

            auto result = TemplateMatcher::matchTemplateSingle(
                match_template, // What to search for
                match_target.value(), // where to look in
                options
            );

            if (args.region.has_value() && toRealworld) {
                const auto region = args.region.value();
                result.X += region.X;
                result.Y += region.Y;
            }

            // debug score
            if (args.cacheable) {
#pragma warning("Cache not implemented yet")
            }

            return static_cast<DResult>(result);

            // Perform detection logic here
        } catch (const Exceptions::LowConfidenceException &e) {
            std::cout << match_template.origin << ": Low confidence exception" << e.what() <<  std::endl;
        } catch (const std::exception &e) {
            // Handle exceptions if necessary
        }


        return std::nullopt;
    }

    std::optional<std::vector<DResult> > Detector::Multiple(Image &match_template, const DArgs &args) {
        return std::nullopt;
    }
}
