#include "LibGame/action/primary/IdlePrimaryStatus.hpp"

namespace LibGame::Action::Primary {

    IdlePrimaryStatus::IdlePrimaryStatus(const Type t) : type(t) {
        fillContext();
    }

    IdlePrimaryStatus::~IdlePrimaryStatus() = default;

    std::string IdlePrimaryStatus::GetPrimaryActionName() {
        return "Idling";
    }

    std::string IdlePrimaryStatus::GetPrimaryActionValue(const Type action) {
        switch(action) {
            case Type::Idle1: return "Standing idle";
            case Type::Idle2: return "Standing legs wide";
            case Type::Idle3: return "Standing, left leg resting on tip of left shoe";
            case Type::Idle4: return "Standing legs closed";
            case Type::Idle5: return "Dominant stands left hand on hips";
            case Type::Idle6: return "Making a call";
            default:          return "unknown activity";
        }
    }

    std::unordered_map<std::string, std::string> IdlePrimaryStatus::getContext() const {
        return store;
    }

    void IdlePrimaryStatus::fillContext() {
        add("Action", GetPrimaryActionName());
        add("Idle", GetPrimaryActionValue(type));
    }

}
