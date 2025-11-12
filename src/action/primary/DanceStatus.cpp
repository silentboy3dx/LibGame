#include "LibGame/action/primary/DanceStatus.hpp"

#include <format>
#include <iostream>
#include <ostream>
#include <stdexcept>

namespace LibGame::Action::Primary {
    DanceStatus::DanceStatus(Type t) : type(t) {
        fillContext();
    }

    DanceStatus::~DanceStatus() = default;

    std::string DanceStatus::GetPrimaryActionName() {
        return "Dancing";
    }

    std::string DanceStatus::GetSecondaryActionName() {
        return "Dance";
    }

    std::string DanceStatus::GetSecondaryActionValue(Type action) {
        std::cout << "DanceStatus::GetSecondaryActionValue(" << static_cast<int>(action) << ")" << std::endl;
        if (int index = static_cast<int>(action); index >= 1 && index <= 47) {
            return "Dance " + std::to_string(index);
        }
        return "unknown activity";
    }

    DanceStatus::Type DanceStatus::TypeFromInt(int value) {
        if (value < 0 || value > 47) {
            throw std::out_of_range(std::format("Value must be between 1 and 47 you gave me {}", value));
        }
        return static_cast<Type>(value);
    }

    std::unordered_map<std::string, std::string> DanceStatus::getContext() const {
        return store;
    }

    void DanceStatus::fillContext() {
        add("Action", GetPrimaryActionName());
        add(GetSecondaryActionName(), GetSecondaryActionValue(type));
    }

}
