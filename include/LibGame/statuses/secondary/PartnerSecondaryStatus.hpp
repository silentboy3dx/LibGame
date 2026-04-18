#pragma once
#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Statuses::Secondary {
    class PartnerSecondaryStatus final : public Misc::KvStore {
    public:
        enum class Type {
            Off,
            Partner
        };

        explicit PartnerSecondaryStatus(const Type t);

        ~PartnerSecondaryStatus() override;

        static std::string GetPrimaryActionName();

        static std::string GetPrimaryActionValue(const Type action);

        static void SetPartner(const std::string &partner);

        [[nodiscard]] std::unordered_map<std::string, std::string> getContext() const;

    private:
        Type type;
        static std::string partner;

        void fillContext();
    };
}
