#include "LibGame/statuses/primary/SlowDanceStatus.hpp"
#include "LibGame/module/Context.hpp"

namespace LibGame::Statuses::Primary {
    SlowDanceStatus::~SlowDanceStatus() = default;

    void SlowDanceStatus::clear() {
        ctx.remove("Slow-dance Partner");
        ctx.remove("Action");
        ctx.remove(GetSecondaryActionName());
    }

    std::string SlowDanceStatus::GetPrimaryActionName() {
        return "Slow-dance";
    }

    std::string SlowDanceStatus::GetSecondaryActionName() {
        return "Slow-dance pose";
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

    std::string SlowDanceStatus::TypeToString(Type enumValue) {
        Type t = enumValue;

        switch (t) {
            case Type::Stop:     return "Stop";
            case Type::Facing:   return "Facing";
            case Type::Behind:   return "Behind";
            case Type::Kiss:     return "Kiss";
        }
        return "Unknown";
    }

    SlowDanceStatus::Type SlowDanceStatus::TypeFromString(const std::string& value) {
        if (value == "Stop")     return Type::Stop;
        if (value == "Facing")   return Type::Facing;
        if (value == "Behind")   return Type::Behind;
        if (value == "Kiss")     return Type::Kiss;

        return Type::Stop;
    }

    void SlowDanceStatus::SetPartner(const std::string &name)  {
        partner = name;
        fillContext();
    }

    void SlowDanceStatus::fillContext() const {
        if (type != Type::Stop) {
            ctx.add("Action", GetPrimaryActionName());
            ctx.add(GetSecondaryActionName(), GetSecondaryActionValue(type));
            if (!partner.empty()) {
                ctx.add("Slow-dance Partner", partner);
            }
        }
    }
}
