#pragma once

#include <LibGraphics/match/MatchResult.hpp>

using namespace LibGraphics::Match;

namespace LibGame::Detect {
    struct DResult : MatchResult {
        static DResult CreateResult(const int x = 0,
           const int y = 0,
           const int width = 0,
           const int height = 0,
           const float score = 0.0f) {
            auto result = DResult();

            result.X = x;
            result.Y = y;
            result.Width = width;
            result.Height = height;
            result.Score = score;

            return result;
        }
    };
}
