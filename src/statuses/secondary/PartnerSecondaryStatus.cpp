<<<<<<<< HEAD:src/statuses/secondary/PartnerSecondaryStatus.cpp
#include "LibGame/statuses/secondary/PartnerSecondaryStatus.hpp"

namespace LibGame::Statuses::Secondary {
========
#include "LibGame/status/secondary/PartnerSecondaryStatus.hpp"

namespace LibGame::Status::Secondary {
>>>>>>>> origin/main:src/status/secondary/PartnerSecondaryStatus.cpp

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
        add("Partner", GetPrimaryActionValue(type));
    }
}
