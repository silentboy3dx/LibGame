#include "LibGame/statuses/secondary/NakedSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Module::Context;

namespace LibGame::Statuses::Secondary {

    NakedSecondaryStatus::~NakedSecondaryStatus() = default;

    void NakedSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

    std::string NakedSecondaryStatus::GetPrimaryActionName() {
        return "Clothing status";
    }

    std::string NakedSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch (action) {
            case Type::Dressed: return "You are dressed";
            case Type::Undressed: return "You are undressed";
            default: return "unknown";
        }
    }

    std::string NakedSecondaryStatus::TypeToString(Type enumValue) {
        Type t = enumValue;

        switch (t) {
            case Type::Dressed:     return "Dressed";
            case Type::Undressed:     return "Undressed";
        }
        return "Unknown";
    }

    NakedSecondaryStatus::Type NakedSecondaryStatus::TypeFromString(const std::string& value) {
        if (value == "Dressed")     return Type::Dressed;
        if (value == "Undressed")     return Type::Undressed;

        return Type::Dressed;
    }

    void NakedSecondaryStatus::fillContext() const {
        ctx.add(GetPrimaryActionName(), GetPrimaryActionValue(type));
    }
}
