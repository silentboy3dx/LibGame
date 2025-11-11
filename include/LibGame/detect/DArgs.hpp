#pragma once

#include <LibGraphics/type/Region.hpp>
#include <LibGraphics/Image.hpp>
#include <optional>

using namespace LibGraphics;
using namespace LibGraphics::Type;

namespace LibGame::Detect {
    struct DArgs {;
        bool cacheable = false;
        bool grayscale = false;
        float confidence = 0.99f;
        std::optional<Region> region = std::nullopt;
        std::optional<Image> match_target; // the big image
    };
}