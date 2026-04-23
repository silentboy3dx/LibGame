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

        static std::string GetPrimaryActionName();
        static std::string GetSecondaryActionName();
        static std::string GetSecondaryActionValue(Type action);

        void SetPartner(const std::string &name);
        void clear() override;

    private:
        Type type;
        std::string partner;

        void fillContext() const;
    };
}
