#include "LibGame/statuses/secondary/CameraSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Module::Context;

namespace LibGame::Statuses::Secondary {
    CameraSecondaryStatus::~CameraSecondaryStatus() = default;

    void CameraSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

    std::string CameraSecondaryStatus::GetPrimaryActionName() {
        return "Camera";
    }

    std::string CameraSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch (action) {
            case Type::FreeCam: return "FreeCam";
            case Type::CharacterCam: return "CharacterCam";
            case Type::EyeCamera: return "EyeCamera";
            case Type::MovieCamera: return "MovieCamera";
            default: return GetPrimaryActionValue(Type::CharacterCam);
        }
    }

    std::string CameraSecondaryStatus::TypeToString(Type enumValue) {
        Type t = enumValue;

        switch (t) {
            case Type::FreeCam: return "FreeCam";
            case Type::CharacterCam: return "CharacterCam";
            case Type::EyeCamera: return "EyeCamera";
            case Type::MovieCamera: return "MovieCamera";
        }
        return "Unknown";
    }

    CameraSecondaryStatus::Type CameraSecondaryStatus::TypeFromString(const std::string &value) {
        if (value == "FreeCam") return Type::FreeCam;
        if (value == "CharacterCam") return Type::CharacterCam;
        if (value == "EyeCamera") return Type::EyeCamera;
        if (value == "MovieCamera") return Type::MovieCamera;

        return Type::CharacterCam;
    }

    void CameraSecondaryStatus::fillContext() const {
        ctx.add(GetPrimaryActionName(), GetPrimaryActionValue(type));
    }
}
