#include "LibGame/action/secondary/StraponSecondaryStatus.hpp"

namespace LibGame::Action::Secondary {

    StraponSecondaryStatus::StraponSecondaryStatus(const Type t) : type(t) {
        fillContext();
    }

    StraponSecondaryStatus::~StraponSecondaryStatus() = default;

    std::string StraponSecondaryStatus::GetPrimaryActionName() {
        return "Wearing Strapon";
    }

    std::string StraponSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch(action) {
            case Type::Off:      return "Off";
            case Type::Penis:    return "Penis";
            case Type::Strapon1: return "Metallic Purple strapon";
            case Type::Strapon2: return "Metallic golden strapon";
            default:             return "unknown type";
        }
    }

    std::unordered_map<std::string, std::string> StraponSecondaryStatus::getContext() const {
        return store;
    }

    void StraponSecondaryStatus::fillContext() {
        add("Strapon type", GetPrimaryActionValue(type));
    }

}
