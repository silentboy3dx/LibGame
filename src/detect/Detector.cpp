#include "LibGame/detect/Detector.hpp"
#include "LibGame/Interactions.hpp"

#include <LibGame/detect/DResult.hpp>

#include <LibGraphics/match/TemplateMatcher.hpp>
#include <LibGraphics/match/MatchOptions.hpp>
#include <LibScreenshots/Screenshot.hpp>

#include "LibScreenshots.hpp"
#include "LibGraphics/match/Region.hpp"

using namespace LibGraphics::Match;
using namespace LibScreenshots;

namespace LibGame::Detect {
    Detector::Detector(Interactions *core) : core(core) {
        matcher = TemplateMatcher();
    }

    std::optional<DResult> Detector::Single(const DArgs &args) const {
        try {
            auto options = MatchOptions();
            Image match_target = args.target;
            std::optional<Image> match_template = args.match_template;

            if (!match_template) {

                /**
                 * I could have made a crop from the screenshot (Image suports cropping) but i have chosen to
                 * screenshot a region of the screen instead for performance reasons.
                 */
                const ScreenshotResult screenshot = [&]() -> ScreenshotResult {
                    if (args.region) {
                        return takes_screenshot(args.region->X,
                                                args.region->Y,
                                                args.region->Width,
                                                args.region->Height);
                    } else {
                        return takes_screenshot();
                    }
                }();
            }

            options.minConfidence = args.confidence;




            // target is big
            // template is small

            auto result = matcher.TemplateMatcher(options);


            // debug score


            // Perform detection logic here
        } catch (const std::exception &e) {
            // Handle exceptions if necessary
        }


        return result;
    }

    std::optional<std::vector<DResult> > Detector::Multiple(DArgs args) const {
    }
}
