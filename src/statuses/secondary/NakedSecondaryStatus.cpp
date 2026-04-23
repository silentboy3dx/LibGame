#include "LibGame/statuses/secondary/NakedSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Module::Context;

namespace LibGame::Statuses::Secondary {

    NakedSecondaryStatus::~NakedSecondaryStatus() = default;

    void NakedSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

    std::string NakedSecondaryStatus::GetPrimaryActionName() {
        return "Dressed";
    }

    std::string NakedSecondaryStatus::GetPrimaryActionValue(const Type action) {
        switch (action) {
            case Type::Dressed: return "You are dressed";
            case Type::Undressed: return "You are undressed";
            default: return "unknown";
        }
    }

    void NakedSecondaryStatus::fillContext() const {
        ctx.add(GetPrimaryActionName(), GetPrimaryActionValue(type));
    }
}
