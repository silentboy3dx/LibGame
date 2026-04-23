#pragma once
#include "LibGame/statuses/secondary/SecondaryStatus.hpp"
#include <string>
#include <unordered_map>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}


namespace LibGame::Statuses::Secondary {
    class StraponSecondaryStatus final : public SecondaryStatus {
    public:
        enum class Type {
            Off,
            Penis,
            Toy1,
            Toy2
        };

        explicit StraponSecondaryStatus(Module::Context &ctx, const Type t) : SecondaryStatus(ctx), type(t) {
            fillContext();
        }

        ~StraponSecondaryStatus() override;
        void clear() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);

    private:
        Type type;

        void fillContext() const;
    };
}
