#pragma once

#include "LibGame/statuses/primary/PrimaryStatus.hpp"

#include <string>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}

namespace LibGame::Statuses::Primary {
    class SlowDanceStatus : public PrimaryStatus {
    public:
        enum class Type { Stop, Facing, Behind, Kiss };

        explicit SlowDanceStatus(Module::Context &ctx, Type t) : PrimaryStatus(ctx), type(t) {
            fillContext();
        };

        ~SlowDanceStatus() override;
        void clear() override;


        static std::string GetPrimaryActionName();
        static std::string GetSecondaryActionName();
        static std::string GetSecondaryActionValue(Type action);
        static std::string TypeToString(Type enumValue);
        static Type TypeFromString(const std::string& value);

        void SetPartner(const std::string &name);

    private:
        Type type;
        std::string partner;

        void fillContext() const;
    };
}
