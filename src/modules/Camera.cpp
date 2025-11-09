#include "LibGame/module/Camera.hpp"

namespace LibGame::Module {
    void Camera::FreeCam() const {
        core->GetInteraction<Keyboard>().Press("F5");
    }

    void Camera::CharCam() const {
        core->GetInteraction<Keyboard>().Press("F6");
    }

    void Camera::EyeView() const {
        core->GetInteraction<Keyboard>().Press("F7");
    }

    void Camera::MovieCam() const {
        core->GetInteraction<Keyboard>().Press("F8");
    }
}
