#pragma once
#include "LibGame/misc/KvStore.hpp"

#include <string>
#include <unordered_map>

<<<<<<<< HEAD:include/LibGame/statuses/secondary/NakedSecondaryStatus.hpp
namespace LibGame::Statuses::Secondary {
========
namespace LibGame::Status::Secondary {
>>>>>>>> origin/main:include/LibGame/status/secondary/NakedSecondaryStatus.hpp

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
