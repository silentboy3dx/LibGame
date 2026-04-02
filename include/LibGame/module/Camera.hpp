#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Camera final : public BaseModule {
    public:
        explicit Camera(Interactions *core) : BaseModule(core) {};

        ~Camera() override = default;

        void FreeCam() const;
        void CharCam() const;
        void EyeView() const;
        void MovieCam() const;
    };
}