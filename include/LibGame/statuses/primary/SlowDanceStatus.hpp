#pragma once

#include "LibGame/misc/KvStore.hpp"

<<<<<<<< HEAD:include/LibGame/statuses/primary/SlowDanceStatus.hpp
namespace LibGame::Statuses::Primary {
========
#include <string>
#include <unordered_map>

namespace LibGame::Status::Primary {
>>>>>>>> origin/main:include/LibGame/status/primary/SlowDanceStatus.hpp
    class SlowDanceStatus : public Misc::KvStore {
    public:
        enum class Type { Stop, Facing, Behind, Kiss };

        explicit SlowDanceStatus(Type t);

        ~SlowDanceStatus() override;

        static std::string GetPrimaryActionName();

        static std::string GetSecondaryActionName();

        static std::string GetSecondaryActionValue(Type action);

        std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        std::string partner;

        // Helper om de context te vullen
        void fillContext();
    };
}
