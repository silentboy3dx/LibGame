#pragma once
#include "LibGame/misc/KvStore.hpp"
#include <string>
#include <unordered_map>

namespace LibGame::Action::Primary {

    class IdlePrimaryStatus final : public Misc::KvStore {
    public:
        enum class Type {
            Idle1,
            Idle2,
            Idle3,
            Idle4,
            Idle5,
            Idle6
        };

        explicit IdlePrimaryStatus(Type t);
        ~IdlePrimaryStatus() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);

        [[nodiscard]] std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        void fillContext();
    };

}
