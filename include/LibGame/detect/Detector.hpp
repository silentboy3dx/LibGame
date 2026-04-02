#pragma once

#include "LibGame/Interactions.hpp"

#include <LibGraphics.hpp>
#include <LibGraphics/match/TemplateMatcher.hpp>
#include <LibGame/detect/DResult.hpp>
#include <LibGame/detect/DArgs.hpp>
#include <optional>
#include <vector>

using namespace LibGraphics;

namespace LibGame::Detect {
    class Detector final : public BaseInteraction {
    public:
        explicit Detector(Interactions *core = nullptr);
        ~Detector() override = default;

        void SetLastTarget(const Image &target);
        [[nodiscard]] Image GetLastTarget() const;


        [[nodiscard]] std::optional<DResult> Single(Image &match_template, const DArgs &args);
        [[nodiscard]] std::optional<std::vector<DResult> > Multiple(Image &match_template, const DArgs &args);

    private:
        TemplateMatcher matcher;
        Image lastTarget;
    };
}
