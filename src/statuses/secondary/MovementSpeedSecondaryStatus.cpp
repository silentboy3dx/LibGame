#include "LibGame/statuses/secondary/MovementSpeedSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Module::Context;

namespace LibGame::Statuses::Secondary {

    MovementSpeedSecondaryStatus::~MovementSpeedSecondaryStatus() = default;

    void MovementSpeedSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

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

    void MovementSpeedSecondaryStatus::fillContext() const {
        ctx.add(GetPrimaryActionName(), GetPrimaryActionValue(type));
    }

}
