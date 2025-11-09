#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Dances final : public BaseModule {
    public:
        explicit Dances(Interactions *core);

        ~Dances() override = default;
        bool Dance(int number = 1);
        void ScrollToTop() const;
    private:
        static std::unordered_map<int, float> _confidences;
        static std::unordered_map<int, Image> _assets;
        const int scrollbarWidth = 4;
        const int cornerOffset = 5;
        const int headerHeight = 20;
        const int headerWidth = 143;
        const int dancesInnerWidth = 134;
        const int dancesInnerHeight = 147;
        DResult _header;

        std::optional<DResult> GetDanceHeader() const;
        std::optional<DResult> GetDanceLocation(int dance = 1) const;
        std::optional<DResult> FindDance(int dance = 1) const;

        void InitAssets() const;

    };
}