#pragma once

#include "LibGame/statuses/primary/PrimaryStatus.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Module {
    class Context; // ← forward declaration
}

namespace LibGame::Statuses::Primary {
    class ActionStatus : public PrimaryStatus {
    public:
        enum class Type { Sit1, Sit2, Lie1, Lie2, Hello, Applause };

        explicit ActionStatus(Module::Context &ctx, const Type t) : PrimaryStatus(ctx), type(t) {
            fillContext();
        }

        ~ActionStatus() override;

        void clear() override;

        static std::string GetPrimaryActionName();

        static std::string GetSecondaryActionName();

        static std::string GetSecondaryActionValue(Type action);

        static std::string TypeToString(Type enumValue);

        static Type TypeFromString(const std::string &value);

    private:
        Type type;
        std::string partner;

        void fillContext() const;
    };
}
