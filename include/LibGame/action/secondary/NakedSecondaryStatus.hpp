#pragma once
#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

namespace LibGame::Action::Secondary {

    class NakedSecondaryStatus final : public Misc::KvStore {
    public:
        enum class Type {
            Dressed,
            Undressed
        };

        explicit NakedSecondaryStatus(Type t);
        ~NakedSecondaryStatus() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);
        [[nodiscard]] std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        void fillContext();
    };

}
