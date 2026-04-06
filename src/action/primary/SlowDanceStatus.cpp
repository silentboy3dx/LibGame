#include "LibGame/action/primary/SlowDanceStatus.hpp"
#include "LibGame/misc/KvStore.hpp"
#include <string>
#include <unordered_map>

namespace LibGame::Action::Primary {
    SlowDanceStatus::SlowDanceStatus(Type t)
        : type(t) {
        fillContext();
    }

    SlowDanceStatus::~SlowDanceStatus() = default;

    std::string SlowDanceStatus::GetPrimaryActionName() {
        return "Slowdance";
    }

    std::string SlowDanceStatus::GetSecondaryActionName() {
        return "Slowdance pose";
    }

    std::string SlowDanceStatus::GetSecondaryActionValue(Type action) {
        switch (action) {
            case Type::Stop: return "Stopped";
            case Type::Facing: return "Face to face";
            case Type::Behind: return "Partner holding me from behind";
            case Type::Kiss: return "Kissing";
            default: return "Unknown";
        }
    }

    std::unordered_map<std::string, std::string> SlowDanceStatus::getContext() const {
        return store;
    }

    void SlowDanceStatus::fillContext() {
        if (type != Type::Stop) {
            add("Action", GetPrimaryActionName());
            add(GetSecondaryActionName(), GetSecondaryActionValue(type));
            if (!partner.empty()) {
                add("Partner", partner);
            }
        }
    }
}
