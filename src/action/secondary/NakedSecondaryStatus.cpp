#include "LibGame/action/secondary/NakedSecondaryStatus.hpp"

namespace LibGame::Action::Secondary {
    NakedSecondaryStatus::NakedSecondaryStatus(const Type t) : type(t) {
        fillContext();
    }

    NakedSecondaryStatus::~NakedSecondaryStatus() = default;

    std::string NakedSecondaryStatus::GetPrimaryActionName() {
        return "Dressed";
    }

    std::string NakedSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch (action) {
            case Type::Dressed: return "You are dressed.";
            case Type::Undressed: return "You are undressed.";
            default: return "unknown";
        }
    }

    std::unordered_map<std::string, std::string> NakedSecondaryStatus::getContext() const {
        return store;
    }

    void NakedSecondaryStatus::fillContext() {
        add("Clothing style", GetPrimaryActionValue(type));
    }
}
