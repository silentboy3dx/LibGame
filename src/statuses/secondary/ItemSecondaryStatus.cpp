#include "LibGame/statuses/secondary/ItemSecondaryStatus.hpp"


namespace LibGame::Statuses::Secondary {

    ItemSecondaryStatus::~ItemSecondaryStatus() = default;

    void ItemSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

    std::string ItemSecondaryStatus::GetPrimaryActionName() {
        return "Consuming Item";
    }

    std::string ItemSecondaryStatus::GetPrimaryActionValue(Type action) {
        switch(action) {
            case Type::None: return "Nothing";
            case Type::Food_Drink: return "Food/Drink";
            default: return "unknown";
        }
    }

    std::string ItemSecondaryStatus::TypeToString(Type enumValue) {
        return GetPrimaryActionValue(enumValue);
    }

    ItemSecondaryStatus::Type ItemSecondaryStatus::TypeFromString(const std::string &value) {
        if (value == "Food/Drink")     return Type::Food_Drink;
        return Type::None;
    }

    void ItemSecondaryStatus::fillContext() const {
        ctx.add(GetPrimaryActionName(), GetPrimaryActionValue(type));
    }
}
