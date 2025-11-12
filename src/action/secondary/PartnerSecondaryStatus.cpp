#include "LibGame/action/secondary/PartnerSecondaryStatus.hpp"

namespace LibGame::Action::Secondary {

    std::string PartnerSecondaryStatus::partner{};

    PartnerSecondaryStatus::PartnerSecondaryStatus(const Type t) : type(t) {
        fillContext();
    }

    PartnerSecondaryStatus::~PartnerSecondaryStatus() = default;

    std::string PartnerSecondaryStatus::GetPrimaryActionName() {
        return "Current Partner";
    }

    std::string PartnerSecondaryStatus::GetPrimaryActionValue(const Type action) {
        return partner;
    }

    void PartnerSecondaryStatus::SetPartner(const std::string& p) {
        partner = p;
    }

    std::unordered_map<std::string, std::string> PartnerSecondaryStatus::getContext() const {
        return store;
    }

    void PartnerSecondaryStatus::fillContext() {
        add("Action", GetPrimaryActionName());
        add("Partner", GetPrimaryActionValue(type));
    }
}
