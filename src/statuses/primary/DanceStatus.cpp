#include "LibGame/statuses/primary/DanceStatus.hpp"
#include "LibGame/module/Context.hpp"

#include <format>
#include <iostream>
#include <ostream>
#include <stdexcept>


namespace LibGame::Statuses::Primary {
    DanceStatus::~DanceStatus() = default;

    void DanceStatus::clear() {
        ctx.remove("Action");
        ctx.remove(GetSecondaryActionName());
    }

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

    DanceStatus::Type DanceStatus::DanceTypeFromInt(int value) {
        if (value < 0 || value > 47) {
            throw std::out_of_range(std::format("Value must be between 1 and 47 you gave me {}", value));
        }
        return static_cast<Type>(value);
    }

    std::string DanceStatus::TypeToString(Type enumValue) {
        Type t = static_cast<Type>(enumValue);

        switch (t) {
            case Type::Dance1: return "Dance1";
            case Type::Dance2: return "Dance2";
            case Type::Dance3: return "Dance3";
            case Type::Dance4: return "Dance4";
            case Type::Dance5: return "Dance5";
            case Type::Dance6: return "Dance6";
            case Type::Dance7: return "Dance7";
            case Type::Dance8: return "Dance8";
            case Type::Dance9: return "Dance9";
            case Type::Dance10: return "Dance10";
            case Type::Dance11: return "Dance11";
            case Type::Dance12: return "Dance12";
            case Type::Dance13: return "Dance13";
            case Type::Dance14: return "Dance14";
            case Type::Dance15: return "Dance15";
            case Type::Dance16: return "Dance16";
            case Type::Dance17: return "Dance17";
            case Type::Dance18: return "Dance18";
            case Type::Dance19: return "Dance19";
            case Type::Dance20: return "Dance20";
            case Type::Dance21: return "Dance21";
            case Type::Dance22: return "Dance22";
            case Type::Dance23: return "Dance23";
            case Type::Dance24: return "Dance24";
            case Type::Dance25: return "Dance25";
            case Type::Dance26: return "Dance26";
            case Type::Dance27: return "Dance27";
            case Type::Dance28: return "Dance28";
            case Type::Dance29: return "Dance29";
            case Type::Dance30: return "Dance30";
            case Type::Dance31: return "Dance31";
            case Type::Dance32: return "Dance32";
            case Type::Dance33: return "Dance33";
            case Type::Dance34: return "Dance34";
            case Type::Dance35: return "Dance35";
            case Type::Dance36: return "Dance36";
            case Type::Dance37: return "Dance37";
            case Type::Dance38: return "Dance38";
            case Type::Dance39: return "Dance39";
            case Type::Dance40: return "Dance40";
            case Type::Dance41: return "Dance41";
            case Type::Dance42: return "Dance42";
            case Type::Dance43: return "Dance43";
            case Type::Dance44: return "Dance44";
            case Type::Dance45: return "Dance45";
            case Type::Dance46: return "Dance46";
            case Type::Dance47: return "Dance47";
        }
        return "Unknown";
    }


    DanceStatus::Type DanceStatus::TypeFromString(const std::string &value) {
        if (value == "Dance1") return Type::Dance1;
        if (value == "Dance2") return Type::Dance2;
        if (value == "Dance3") return Type::Dance3;
        if (value == "Dance4") return Type::Dance4;
        if (value == "Dance5") return Type::Dance5;
        if (value == "Dance6") return Type::Dance7;
        if (value == "Dance8") return Type::Dance8;
        if (value == "Dance9") return Type::Dance9;
        if (value == "Dance10") return Type::Dance10;
        if (value == "Dance11") return Type::Dance11;
        if (value == "Dance12") return Type::Dance12;
        if (value == "Dance13") return Type::Dance13;
        if (value == "Dance14") return Type::Dance14;
        if (value == "Dance15") return Type::Dance15;
        if (value == "Dance16") return Type::Dance16;
        if (value == "Dance17") return Type::Dance17;
        if (value == "Dance18") return Type::Dance18;
        if (value == "Dance19") return Type::Dance19;
        if (value == "Dance20") return Type::Dance20;
        if (value == "Dance21") return Type::Dance21;
        if (value == "Dance22") return Type::Dance22;
        if (value == "Dance23") return Type::Dance23;
        if (value == "Dance24") return Type::Dance24;
        if (value == "Dance25") return Type::Dance25;
        if (value == "Dance26") return Type::Dance26;
        if (value == "Dance27") return Type::Dance27;
        if (value == "Dance28") return Type::Dance28;
        if (value == "Dance29") return Type::Dance29;
        if (value == "Dance30") return Type::Dance30;
        if (value == "Dance31") return Type::Dance31;
        if (value == "Dance32") return Type::Dance32;
        if (value == "Dance33") return Type::Dance33;
        if (value == "Dance34") return Type::Dance34;
        if (value == "Dance35") return Type::Dance35;
        if (value == "Dance36") return Type::Dance36;
        if (value == "Dance37") return Type::Dance37;
        if (value == "Dance38") return Type::Dance38;
        if (value == "Dance39") return Type::Dance39;
        if (value == "Dance40") return Type::Dance40;
        if (value == "Dance41") return Type::Dance41;
        if (value == "Dance42") return Type::Dance42;
        if (value == "Dance43") return Type::Dance43;
        if (value == "Dance44") return Type::Dance44;
        if (value == "Dance45") return Type::Dance45;
        if (value == "Dance46") return Type::Dance46;
        if (value == "Dance47") return Type::Dance47;

        return static_cast<Type>(Type::Dance1);
    }

    void DanceStatus::fillContext() const {
        ctx.add("Action", GetPrimaryActionName());
        ctx.add(GetSecondaryActionName(), GetSecondaryActionValue(type));
    }
}
