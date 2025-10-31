#pragma once

#include "LibGame/Interactions.hpp"
#include "LibGame/BaseInteraction.hpp"

#include <LibGraphics/match/TemplateMatcher.hpp>
#include <LibGame/detect/DResult.hpp>
#include <LibGame/detect/DArgs.hpp>
#include <optional>
#include <vector>


namespace LibGame::Detect {
    class Detector final : public BaseInteraction {
    public:
        explicit Detector(Interactions* core = nullptr);
        ~Detector() override = default;

        [[nodiscard]] std::optional<DResult> Single(const DArgs &args) const;
        [[nodiscard]] std::optional<std::vector<DResult>> Multiple(DArgs args) const;

    private:
        Interactions * core;
        TemplateMatcher matcher;
    };
}