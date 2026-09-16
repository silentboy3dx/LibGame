#pragma once
#include "LibGame/statuses/secondary/SecondaryStatus.hpp"
#include "LibGame/module/Context.hpp"
#include <string>

namespace LibGame::Statuses::Secondary {

    class ItemSecondaryStatus final : public SecondaryStatus {
    public:

        enum class Type {
            None,
            Food_Drink,
        };

        explicit ItemSecondaryStatus(Module::Context &ctx, const Type t) : SecondaryStatus(ctx), type(t) {
            fillContext();
        }

        ~ItemSecondaryStatus() override;
        void clear() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);
        static std::string TypeToString(Type enumValue);
        static Type TypeFromString(const std::string& value);

    private:
        Type type;

        void fillContext() const;
    };
}
