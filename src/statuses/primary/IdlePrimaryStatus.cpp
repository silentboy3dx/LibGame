#include "LibGame/statuses/primary/IdlePrimaryStatus.hpp"
#include "LibGame/module/Context.hpp"

namespace LibGame::Statuses::Primary {
    IdlePrimaryStatus::~IdlePrimaryStatus() = default;

    void IdlePrimaryStatus::clear() {
        ctx.remove("Action");
        ctx.remove(GetSecondaryActionName());
    }

    std::string IdlePrimaryStatus::GetPrimaryActionName() {
        return "Idling";
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

    void IdlePrimaryStatus::fillContext() {
        ctx.add("Action", GetPrimaryActionName());
        ctx.add(GetSecondaryActionName(),  GetSecondaryActionValue(type));
    }
}
