#pragma once

#include "BaseModule.hpp"

#include <optional>

namespace LibGame::Module {
    class ImageReader final : public BaseModule {
    public:
        explicit ImageReader(Interactions *core) : BaseModule(core) {
        };

        ~ImageReader() override = default;

        std::optional<std::string>  ImageToText(Image image, float min_confidence = -1.0f, bool debug = false) const;

    };
}
