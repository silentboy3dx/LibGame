#pragma once

#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Action::Primary {
    class ActionStatus : public Misc::KvStore {
    public:
        enum class Type { Sit1, Sit2, Lie1, Lie2, Hello, Applause };

        // Constructor & destructor
        explicit ActionStatus(Type t);

        ~ActionStatus();

        // Primaire actie naam
        static std::string GetPrimaryActionName();

        // Subactie (pose) naam
        static std::string GetSecondaryActionName();

        // Subactie waarde
        static std::string GetSecondaryActionValue(Type action);

        // Override van KvStore → levert alle contextregels
        std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        std::string partner;

        // Helper om de context te vullen
        void fillContext();
    };
}
