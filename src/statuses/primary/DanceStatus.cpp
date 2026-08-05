#include "LibGame/statuses/primary/DanceStatus.hpp"
#include "LibGame/module/Context.hpp"

#include <format>
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
        switch (action) {
            case Type::Dance1: return "Dance 1 — Basic hip-hop groove";
            case Type::Dance2: return "Dance 2 — Casual club shuffle";
            case Type::Dance3: return "Dance 3 — Light pop dance";
            case Type::Dance4: return "Dance 4 — Energetic EDM festival dance";
            case Type::Dance5: return "Dance 5 — Sexy hip-hop body roll";
            case Type::Dance6: return "Dance 6 — Smooth Latin-inspired groove";
            case Type::Dance7: return "Dance 7 — Robotic popping dance";
            case Type::Dance8: return "Dance 8 — Hands-up club dance";
            case Type::Dance9: return "Dance 9 — Casual club sway";
            case Type::Dance10: return "Dance 10 — Pop step-touch dance";
            case Type::Dance11: return "Dance 11 — Hip-hop bounce rhythm";
            case Type::Dance12: return "Dance 12 — Slow sexy club dance";
            case Type::Dance13: return "Dance 13 — EDM shuffle dance";
            case Type::Dance14: return "Dance 14 — Hip-hop footwork pattern";
            case Type::Dance15: return "Dance 15 — Slow R&B groove";
            case Type::Dance16: return "Dance 16 — Club dance with hip movement";
            case Type::Dance17: return "Dance 17 — Gangnam Style";
            case Type::Dance18: return "Dance 18 — Shuffle dance pattern";
            case Type::Dance19: return "Dance 19 — Popping wave dance";
            case Type::Dance20: return "Dance 20 — Festival jump dance";
            case Type::Dance21: return "Dance 21 — Club shuffle variation";
            case Type::Dance22: return "Dance 22 — Sexy hip-hop groove";
            case Type::Dance23: return "Dance 23 — Shuffle dance with arm flow";
            case Type::Dance24: return "Dance 24 — Light pop dance variation";
            case Type::Dance25: return "Dance 25 — Hip-hop groove pattern";
            case Type::Dance26: return "Dance 26 — Fast shuffle dance";
            case Type::Dance27: return "Dance 27 — Sexy club dance variation";
            case Type::Dance28: return "Dance 28 — Hip-hop wave movement";
            case Type::Dance29: return "Dance 29 — Shuffle dance variation";
            case Type::Dance30: return "Dance 30 — Pop dance variation";
            case Type::Dance31: return "Dance 31 — Hip-hop bounce variation";
            case Type::Dance32: return "Dance 32 — Sexy EDM dance";
            case Type::Dance33: return "Dance 33 — Shuffle dance pattern";
            case Type::Dance34: return "Dance 34 — Casual club dance";
            case Type::Dance35: return "Dance 35 — Hip-hop groove variation";
            case Type::Dance36: return "Dance 36 — Festival shuffle dance";
            case Type::Dance37: return "Dance 37 — Hard shuffle dance";
            case Type::Dance38: return "Dance 38 — Club dance variation";
            case Type::Dance39: return "Dance 39 — Shuffle dance with footwork";
            case Type::Dance40: return "Dance 40 — Modern EDM club dance";
            case Type::Dance41: return "Dance 41 — Shuffle dance with armflow";
            case Type::Dance42: return "Dance 42 — Fast hip-hop footwork";
            case Type::Dance43: return "Dance 43 — Sexy bodywave dance";
            case Type::Dance44: return "Dance 44 — Festival shuffle variation";
            case Type::Dance45: return "Dance 45 — Latin hip movement dance";
            case Type::Dance46: return "Dance 46 — Upbeat pop dance";
            case Type::Dance47: return "Dance 47 — Fast shuffle with footwork";
            default: return "Unknown dance";
        }
    }

    DanceStatus::Type DanceStatus::DanceTypeFromInt(int value) {
        if (value < 0 || value > 47) {
            throw std::out_of_range(std::format("Value must be between 1 and 47 you gave me {}", value));
        }
        return static_cast<Type>(value);
    }

    std::string DanceStatus::TypeToString(Type enumValue) {
        Type t = enumValue;

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
        if (value == "Dance6") return Type::Dance6;
        if (value == "Dance7") return Type::Dance7;
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


        return Type::Dance1;
    }

    void DanceStatus::fillContext() const {
        ctx.add("Action", GetPrimaryActionName());
        ctx.add(GetSecondaryActionName(), GetSecondaryActionValue(type));
    }
}
