#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {

    struct GiftSender
    {
        std::string Sender = "Unknown";
        std::string Message;
    };

    class Gift final : public BaseModule {
    public:
        explicit Gift(Interactions *core) : BaseModule(core) {};

        ~Gift() override = default;

        std::optional<GiftSender> GetLatestGiftFromProfile();
        std::optional<GiftSender> ReadLastestGift();

    private:
        static constexpr int FRIENDS_LIST_WIDTH = 140;
        static constexpr int PROFILE_WINDOW_WIDTH = 678;

        const int FriendsListWidth = 150;
        const int ProfileWidth = 650;
        const int GiftSeperatorLeftOffset = 26;
        const int ProfileMaxHeight = 550;

        bool GoToMyGifts() const;
    };
}