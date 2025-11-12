#include "LibGame/action/secondary/MovementSpeedSecondaryStatus.hpp"

namespace LibGame::Action::Secondary {

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
