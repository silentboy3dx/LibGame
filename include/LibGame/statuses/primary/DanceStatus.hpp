#pragma once
#include "LibGame/misc/KvStore.hpp"
#include <string>
#include <unordered_map>

<<<<<<<< HEAD:include/LibGame/statuses/primary/DanceStatus.hpp
namespace LibGame::Statuses::Primary  {
========
namespace LibGame::Status::Primary  {
>>>>>>>> origin/main:include/LibGame/status/primary/DanceStatus.hpp

    class DanceStatus : public Misc::KvStore {
    public:
        enum class Type {
            Dance1, Dance2, Dance3, Dance4, Dance5, Dance6, Dance7, Dance8, Dance9, Dance10,
            Dance11, Dance12, Dance13, Dance14, Dance15, Dance16, Dance17, Dance18, Dance19, Dance20,
            Dance21, Dance22, Dance23, Dance24, Dance25, Dance26, Dance27, Dance28, Dance29, Dance30,
            Dance31, Dance32, Dance33, Dance34, Dance35, Dance36, Dance37, Dance38, Dance39, Dance40,
            Dance41, Dance42, Dance43, Dance44, Dance45, Dance46, Dance47
        };

        explicit DanceStatus(Type t);
        ~DanceStatus() override;

        static std::string GetPrimaryActionName();
        static std::string GetSecondaryActionName();
        static std::string GetSecondaryActionValue(Type action);

        static Type TypeFromInt(int value);

        std::unordered_map<std::string, std::string> getContext() const override;

    private:
        Type type;
        void fillContext();
    };

}
