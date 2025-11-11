#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Friends final : public BaseModule {
    public:
        explicit Friends(Interactions *core) : BaseModule(core) {};

        ~Friends() override = default;

        std::vector<std::string> GetOnlineFriends();
        bool isFriendOnline(const std::string& name);

    private:
        static constexpr int FRIENDS_LIST_WIDTH = 140;
        static constexpr int FRIENDS_MAX_HEIGHT = 460;
        static constexpr int FRIENDS_NAME_HEIGHT = 24;
        static constexpr int LABEL_ONLINE_FRIENDS_TOP_OFFSET = 69;

        static std::string stripAndTrim(const std::string& input);
    };
}