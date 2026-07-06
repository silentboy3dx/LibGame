#include "LibGame/statuses/primary/ActionStatus.hpp"
#include "LibGame/module/Context.hpp"

#include <string>

namespace LibGame::Statuses::Primary {
    ActionStatus::~ActionStatus() = default;

    void ActionStatus::clear() {
        ctx.remove("Action");
        ctx.remove(GetSecondaryActionName());
    }

    std::string ActionStatus::GetPrimaryActionName() {
        return "Performing Action";
    }

    std::string ActionStatus::GetSecondaryActionName() {
        return "Action performed";
    }

    std::string ActionStatus::GetSecondaryActionValue(Type action) {
        switch (action) {
            case Type::Sit1: return "Sitting on the floor";
            case Type::Sit2: return "Levitating in a cross-legged pose";
            case Type::Lie1: return "Lying on my back, staring at the ceiling";
            case Type::Lie2: return "Lying on my belly, head turned to the left";
            case Type::Hello: return "Waving hello";
            case Type::Applause: return "Standing and clapping hands";
            default: return "Unknown";
        }
    }

    std::string ActionStatus::TypeToString(Type enumValue) {
        Type t = enumValue;

        switch (t) {
            case Type::Sit1:     return "Sit1";
            case Type::Sit2:     return "Sit2";
            case Type::Lie1:     return "Lie1";
            case Type::Lie2:     return "Lie2";
            case Type::Hello:    return "Hello";
            case Type::Applause: return "Applause";
        }
        return "Unknown";
    }

    ActionStatus::Type ActionStatus::TypeFromString(const std::string &value) {
        if (value == "Sit1")     return Type::Sit1;
        if (value == "Sit2")     return Type::Sit2;
        if (value == "Lie1")     return Type::Lie1;
        if (value == "Lie2")     return Type::Lie2;
        if (value == "Hello")    return Type::Hello;
        if (value == "Applause") return Type::Applause;

        return Type::Sit1;
    }

    void ActionStatus::fillContext() const {
        ctx.add("Action", GetPrimaryActionName());
        ctx.add(GetSecondaryActionName(), GetSecondaryActionValue(type));
    }
}
