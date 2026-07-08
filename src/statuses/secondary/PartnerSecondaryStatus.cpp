#include "LibGame/statuses/secondary/PartnerSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Module::Context;

namespace LibGame::Statuses::Secondary {

    std::string PartnerSecondaryStatus::partner = "";

    PartnerSecondaryStatus::~PartnerSecondaryStatus() = default;

    void PartnerSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

    std::string PartnerSecondaryStatus::GetPrimaryActionName() {
        return "Current Partner";
    }

    std::string PartnerSecondaryStatus::GetPrimaryActionValue(const Type action) {
        return partner;
    }

    std::string PartnerSecondaryStatus::TypeToString(Type enumValue) {
        Type t = static_cast<Type>(enumValue);

        switch (t) {
            case Type::Off:     return "Off";
            case Type::Partner:     return "Partner";
        }
        return "Unknown";
    }

    PartnerSecondaryStatus::Type PartnerSecondaryStatus::TypeFromString(const std::string& value) {
        if (value == "Off")     return Type::Off;
        if (value == "Partner")     return Type::Partner;

        return Type::Off;
    }

    void PartnerSecondaryStatus::fillContext() const {
        SetPartner("");
    }

    void PartnerSecondaryStatus::SetPartner(const std::string& p) const {
        ctx.add(GetPrimaryActionName(), p);
    }
}
