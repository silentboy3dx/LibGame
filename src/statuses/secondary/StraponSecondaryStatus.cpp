<<<<<<<< HEAD:src/statuses/secondary/StraponSecondaryStatus.cpp
#include "LibGame/statuses/secondary/StraponSecondaryStatus.hpp"

namespace LibGame::Statuses::Secondary {
========
#include "LibGame/status/secondary/StraponSecondaryStatus.hpp"

namespace LibGame::Status::Secondary {
>>>>>>>> origin/main:src/status/secondary/StraponSecondaryStatus.cpp
    StraponSecondaryStatus::StraponSecondaryStatus(const Type t) : type(t) {
        fillContext();
    }

    StraponSecondaryStatus::~StraponSecondaryStatus() = default;

    std::string StraponSecondaryStatus::GetPrimaryActionName() {
        return "Wearing Strapon";
    }

    std::string StraponSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch (action) {
            case Type::Off: return "Off";
            case Type::Penis: return "Penis";
            case Type::Toy1: return "Metallic Purple strapon";
            case Type::Toy2: return "Metallic golden strapon";
            default: return "unknown type";
        }
    }

    std::unordered_map<std::string, std::string> StraponSecondaryStatus::getContext() const {
        return store;
    }

    void StraponSecondaryStatus::fillContext() {
        if (type != Type::Off) {
            add("Strapon type", GetPrimaryActionValue(type));
        }
    }
}
