#pragma once

#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Action::Primary {
    class SlowDanceStatus : public Misc::KvStore {
    public:
        enum class Type { Stop, Facing, Behind, Kiss };

        // Constructor & destructor
        explicit SlowDanceStatus(Type t);

        ~SlowDanceStatus();

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
