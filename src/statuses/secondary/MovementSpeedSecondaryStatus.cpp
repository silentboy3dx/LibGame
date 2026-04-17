<<<<<<<< HEAD:src/statuses/secondary/MovementSpeedSecondaryStatus.cpp
#include "LibGame/statuses/secondary/MovementSpeedSecondaryStatus.hpp"

namespace LibGame::Statuses::Secondary {
========
#include "LibGame/status/secondary/MovementSpeedSecondaryStatus.hpp"

namespace LibGame::Status::Secondary {
>>>>>>>> origin/main:src/status/secondary/MovementSpeedSecondaryStatus.cpp

    MovementSpeedSecondaryStatus::MovementSpeedSecondaryStatus(const Type t) : type(t) {
        fillContext();
    }

    MovementSpeedSecondaryStatus::~MovementSpeedSecondaryStatus() = default;

    std::string MovementSpeedSecondaryStatus::GetPrimaryActionName() {
        return "Movement Type";
    }

    std::string MovementSpeedSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch(action) {
            case Type::Walking: return "Walking";
            case Type::Running: return "Running";
            default:            return "unknown";
        }
    }

    std::unordered_map<std::string, std::string> MovementSpeedSecondaryStatus::getContext() const {
        return store;
    }

    void MovementSpeedSecondaryStatus::fillContext() {
        add("Movement type", GetPrimaryActionValue(type));
    }

}
