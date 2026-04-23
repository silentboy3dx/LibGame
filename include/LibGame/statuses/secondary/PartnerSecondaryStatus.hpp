#pragma once
#include "LibGame/statuses/secondary/SecondaryStatus.hpp"

#include <string>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}

namespace LibGame::Statuses::Secondary {
    class PartnerSecondaryStatus final : public SecondaryStatus {
    public:

        enum class Type {
            Off,
            Partner
        };

        static std::string partner;

        explicit PartnerSecondaryStatus(Module::Context &ctx, const Type t) : SecondaryStatus(ctx), type(t) {
            fillContext();
        }

        ~PartnerSecondaryStatus() override;
        void clear() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);

        void SetPartner(const std::string &partner) const;

    private:
        void fillContext() const;
        Type type;
    };
}
