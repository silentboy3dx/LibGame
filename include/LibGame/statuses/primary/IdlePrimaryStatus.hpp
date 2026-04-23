#pragma once
#include "LibGame/statuses/primary/PrimaryStatus.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}

namespace LibGame::Statuses::Primary {

    class IdlePrimaryStatus final : public PrimaryStatus {
    public:
        enum class Type {
            Idle1,
            Idle2,
            Idle3,
            Idle4,
            Idle5,
            Idle6
        };

        explicit IdlePrimaryStatus(Module::Context &ctx, Type t) : PrimaryStatus(ctx), type(t) {
            fillContext();
        }

        ~IdlePrimaryStatus() override;

        static std::string GetPrimaryActionName();
        static std::string GetSecondaryActionName();
        static std::string GetSecondaryActionValue(Type action);
        void clear() override;

    private:
        Type type;
        void fillContext();
    };

}
