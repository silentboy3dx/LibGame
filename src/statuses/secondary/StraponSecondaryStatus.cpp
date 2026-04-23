#include "LibGame/statuses/secondary/StraponSecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"

using LibGame::Module::Context;

namespace LibGame::Statuses::Secondary {

    StraponSecondaryStatus::~StraponSecondaryStatus() = default;

    void StraponSecondaryStatus::clear() {
        ctx.remove(GetPrimaryActionName());
    }

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

    void StraponSecondaryStatus::fillContext() const {
        if (type != Type::Off) {
            ctx.add(GetPrimaryActionName(), GetPrimaryActionValue(type));
        }
    }
}
