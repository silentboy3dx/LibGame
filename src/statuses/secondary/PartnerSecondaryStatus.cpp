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

    void PartnerSecondaryStatus::fillContext() const {
        SetPartner("");
    }

    void PartnerSecondaryStatus::SetPartner(const std::string& p) const {
        ctx.add(GetPrimaryActionName(), p);
    }
}
