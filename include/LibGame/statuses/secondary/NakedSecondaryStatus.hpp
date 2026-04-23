#pragma once
#include "LibGame/statuses/secondary/SecondaryStatus.hpp"
#include <string>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}

namespace LibGame::Statuses::Secondary {

    class NakedSecondaryStatus final : public SecondaryStatus {
    public:
        enum class Type {
            Dressed,
            Undressed
        };

        explicit NakedSecondaryStatus(Module::Context &ctx, const Type t) : SecondaryStatus(ctx), type(t) {
            fillContext();
        }

        ~NakedSecondaryStatus() override;
        void clear() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);

    private:
        Type type;
        void fillContext() const;
    };

}
