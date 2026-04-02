#include "LibGame/module/ImageReader.hpp"

using Ocr::OcrTextReader;

namespace LibGame::Module {
    std::optional<std::string> ImageReader::ImageToText(Image image, float min_confidence, bool debug) const {
        try {
            auto [text, confidence] = OcrTextReader::ReadFromImage(image);

            if (confidence >= min_confidence) {
                return text;
            }

        } catch (...) {

        }
        return "";
    }
}
