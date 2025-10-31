#pragma once

#include <LibGraphics/match/Region.hpp>
#include <LibGraphics/Image.hpp>
#include <optional>

using namespace LibGraphics;

namespace LibGame::Detect {
    struct DArgs {;
        bool cacheable = false;
        bool grayscale = false;
        bool toRealworld = false;
        float confidence = 0.99f;
        std::optional<Region> region = std::nullopt;
        std::optional<Image> match_template = std::nullopt;
        Image target;
    };
}