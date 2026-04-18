#pragma once

#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Statuses::Primary {
    class ActionStatus : public Misc::KvStore {
    public:
        enum class Type { Sit1, Sit2, Lie1, Lie2, Hello, Applause };

        // Constructor & destructor
        explicit ActionStatus(Type t);

        ~ActionStatus() override;

        static std::string GetPrimaryActionName();

        static std::string GetSecondaryActionName();

        static std::string GetSecondaryActionValue(Type action);

        std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        std::string partner;

        void fillContext();
    };
}
