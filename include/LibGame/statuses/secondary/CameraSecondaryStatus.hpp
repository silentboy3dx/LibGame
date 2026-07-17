#pragma once
#include "LibGame/statuses/secondary/SecondaryStatus.hpp"
#include <string>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}


namespace LibGame::Statuses::Secondary {
    class CameraSecondaryStatus final : public SecondaryStatus {
    public:
        enum class Type {
            FreeCam,
            CharacterCam,
            EyeCamera,
            MovieCamera
        };

        explicit CameraSecondaryStatus(Module::Context &ctx, const Type t) : SecondaryStatus(ctx), type(t) {
            fillContext();
        }

        ~CameraSecondaryStatus() override;
        void clear() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);
        static std::string TypeToString(Type enumValue);
        static Type TypeFromString(const std::string& value);

    private:
        Type type;

        void fillContext() const;
    };
}
