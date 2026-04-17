#pragma once
#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

<<<<<<<< HEAD:include/LibGame/statuses/secondary/MovementSpeedSecondaryStatus.hpp
namespace LibGame::Statuses::Secondary {
========
namespace LibGame::Status::Secondary {
>>>>>>>> origin/main:include/LibGame/status/secondary/MovementSpeedSecondaryStatus.hpp

    class MovementSpeedSecondaryStatus final : public Misc::KvStore {
    public:
        enum class Type {
            Walking,
            Running
        };

        explicit MovementSpeedSecondaryStatus(Type t);
        ~MovementSpeedSecondaryStatus() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);

        [[nodiscard]] std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        void fillContext();
    };

}
