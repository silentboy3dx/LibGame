#include "LibGame/statuses/primary/IdlePrimaryStatus.hpp"
#include "LibGame/module/Context.hpp"

namespace LibGame::Statuses::Primary {
    IdlePrimaryStatus::~IdlePrimaryStatus() = default;

    void IdlePrimaryStatus::clear() {
        ctx.remove("Action");
        ctx.remove(GetSecondaryActionName());
    }

    std::string IdlePrimaryStatus::GetPrimaryActionName() {
        return "Idling pose";
    }

    std::string IdlePrimaryStatus::GetSecondaryActionName() {
        return "Idle";
    }

    std::string IdlePrimaryStatus::GetSecondaryActionValue(const Type action) {
        switch (action) {
            case Type::Idle1: return "Standing idle";
            case Type::Idle2: return "Standing legs wide";
            case Type::Idle3: return "Standing, left leg resting on tip of left shoe";
            case Type::Idle4: return "Standing legs closed";
            case Type::Idle5: return "Dominant stands left hand on hips";
            case Type::Idle6: return "Making a call";
            default: return "unknown activity";
        }
    }

    std::string IdlePrimaryStatus::TypeToString(Type enumValue) {
        Type t = static_cast<Type>(enumValue);

        switch (t) {
            case Type::Idle1:     return "Idle1";
            case Type::Idle2:     return "Idle2";
            case Type::Idle3:     return "Idle3";
            case Type::Idle4:     return "Idle4";
            case Type::Idle5:     return "Idle5";
            case Type::Idle6:     return "Idle6";
        }
        return "Unknown";
    }

    IdlePrimaryStatus::Type IdlePrimaryStatus::TypeFromString(const std::string& value) {
        if (value == "Idle1")     return Type::Idle1;
        if (value == "Idle2")     return Type::Idle2;
        if (value == "Idle3")     return Type::Idle3;
        if (value == "Idle4")     return Type::Idle4;
        if (value == "Idle5")     return Type::Idle5;
        if (value == "Idle6")     return Type::Idle6;

        return Type::Idle1;
    }

    void IdlePrimaryStatus::fillContext() const {
        ctx.add("Action", GetPrimaryActionName());
        ctx.add(GetSecondaryActionName(),  GetSecondaryActionValue(type));
    }
}
