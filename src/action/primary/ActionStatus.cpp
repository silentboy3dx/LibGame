#include "LibGame/action/primary/ActionStatus.hpp"
#include "LibGame/misc/KvStore.hpp"
#include <string>
#include <unordered_map>

namespace LibGame::Action::Primary {
    ActionStatus::ActionStatus(Type t)
        : type(t) {
        fillContext();
    }

    ActionStatus::~ActionStatus() = default;

    std::string ActionStatus::GetPrimaryActionName() {
        return "Performing Action";
    }

    std::string ActionStatus::GetSecondaryActionName() {
        return "Action";
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

    std::unordered_map<std::string, std::string> ActionStatus::getContext() const {
        return store;
    }

    void ActionStatus::fillContext() {
        add(GetSecondaryActionName(), GetSecondaryActionValue(type));
        if (!partner.empty()) {
            add("Partner", partner);
        }
    }
}
