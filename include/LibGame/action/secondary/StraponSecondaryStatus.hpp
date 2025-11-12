#pragma once
#include "LibGame/misc/KvStore.hpp"
#include <string>
#include <unordered_map>

namespace LibGame::Action::Secondary {

    class StraponSecondaryStatus final : public Misc::KvStore {
    public:
        enum class Type {
            Off,
            Penis,
            Toy1,
            Toy2
        };

        explicit StraponSecondaryStatus(const Type t);
        ~StraponSecondaryStatus() override;

        static std::string GetPrimaryActionName();
        static std::string GetPrimaryActionValue(Type action);

        [[nodiscard]] std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        void fillContext();
    };

}
