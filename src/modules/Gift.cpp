#include "LibGame/module/Gift.hpp"

#include <iostream>
#include <LibGraphics/type/Rect.hpp>

#include "LibGame/misc/Point.hpp"
#include "LibGame/misc/Rect.hpp"
#include "LibGame/module/Friends.hpp"
#include "LibGame/module/ImageReader.hpp"
#include "LibGame/module/Profile.hpp"

using Type::Rect;
using namespace LibGame::Misc;

namespace LibGame::Module {
    bool Gift::GoToMyGifts() const {
        return ClickIfVisible("gift/button_my_gifts.png", 0.98f, true, false, true);
    }

    std::optional<GiftSender> Gift::GetLatestGiftFromProfile() const {
        const auto profile = core->GetInteraction<Profile>();
        std::optional<GiftSender> result = std::nullopt;

        const bool profile_open = profile.OpenMyProfile();

        if (profile_open) {
            std::this_thread::sleep_for(std::chrono::microseconds(900));
            result = OpenAndReadLastGift();
        }

        (void) profile.CloseProfile();

        std::this_thread::sleep_for(std::chrono::microseconds(350));

        return result;
    }

    std::optional<GiftSender> Gift::ReadLastestGift() const {
        const auto screenshot = core->GetInteraction<Screenshot>().Take();

        auto args = DArgs(0.98f, false, false, true);
        args.match_target = screenshot;

        const auto btn_result = GetAsset("gift/button_my_gifts_highlighted.png", args);

        GiftSender sender{.Message = "No message found"};

        if (screenshot.isValid() && btn_result.has_value()) {
            const auto giftbutton = btn_result.value();
            const auto innerToLeft = Point(giftbutton.X - 192, giftbutton.Y + giftbutton.Height);

            if (auto const seperator_result = GetAsset("gift/gift_seperator.png"); seperator_result.has_value()) {
                const auto seperator = seperator_result.value();


                auto gift = screenshot.crop(innerToLeft.X, innerToLeft.Y, PROFILE_WINDOW_WIDTH - FRIENDS_LIST_WIDTH,
                                            seperator.Y - innerToLeft.Y);

                args = DArgs(0.99f, true);
                args.match_target = gift;

                auto const btnDelete = GetAsset("gift/button_delete.png", args);
                auto const btnReport = GetAsset("gift/button_report.png", args);

                if (btnDelete.has_value() && btnReport.has_value()) {
                    // const auto deleteButton = btnDelete.value();
                    const auto reportButton = btnReport.value();

                    int nameWidth = 115;
                    int nameHeight = 37;
                    int padding = 10;

                    const Type::Rect cropRegion = {
                        reportButton.X - (nameWidth + padding), reportButton.Y, nameWidth, nameHeight
                    };
                    const Type::Rect imageRegion = {0, 62, 491, 268};

                    int calculatedHeight = gift.height - (imageRegion.Height + imageRegion.Y);
                    int calculatedWidth = (ProfileWidth - FriendsListWidth);
                    calculatedWidth += 5;
                    int calculatedY = gift.height - calculatedHeight;

                    auto nameCrop = gift.crop(cropRegion.X, cropRegion.Y - 16, cropRegion.Width, cropRegion.Height);
                    auto textCrop = gift.crop(0, calculatedY, calculatedWidth, calculatedHeight);

                    auto messageText = core->GetInteraction<ImageReader>().ImageToText(textCrop, 0.8f, true);
                    auto nameText = core->GetInteraction<ImageReader>().ImageToText(nameCrop, 0.8f, true);

                    GiftSender sender{
                        .Sender = nameText.value_or("Unknow"), .Message = messageText.value_or("No text found")
                    };;

                    return sender;
                }

                // gift.show();
                // mouse->MoveTo(seperator.X, seperator.Y);
            }
        }

        return std::nullopt;
    }

    std::optional<GiftSender> Gift::OpenAndReadLastGift() const {
        const auto screenshot = core->GetInteraction<Screenshot>().Take();

        auto args = DArgs(0.97f, false, false, true); // 0.97f local
        args.match_target = screenshot;

        const auto btn_result = GetAsset("gift/button_my_gifts.png", args);

        GiftSender sender{.Message = "No message found"};

        std::cerr << "btn_result.has_value() " << btn_result.has_value() << std::endl;
        std::cerr << "screenshot.isValid() " << screenshot.isValid() << std::endl;
        if (screenshot.isValid() && btn_result.has_value()) {
            const auto giftbutton = btn_result.value();
            const auto innerToLeft = Point(giftbutton.X - 192, giftbutton.Y + giftbutton.Height);


            mouse->MoveToAndClick(giftbutton.X, giftbutton.Y);

            if (auto const seperator_result = GetAsset("gift/gift_seperator.png"); seperator_result.has_value()) {
                const auto seperator = seperator_result.value();


                auto gift = screenshot.crop(innerToLeft.X, innerToLeft.Y, PROFILE_WINDOW_WIDTH - FRIENDS_LIST_WIDTH,
                                            seperator.Y - innerToLeft.Y);

                args = DArgs(0.99f, true);
                args.match_target = gift;

                auto const btnDelete = GetAsset("gift/button_delete.png", args);
                auto const btnReport = GetAsset("gift/button_report.png", args);

                std::cerr << "btnDelete.has_value() " << btnDelete.has_value() << std::endl;
                std::cerr << "btnReport.has_value() " << btnReport.has_value() << std::endl;

                if (btnDelete.has_value() && btnReport.has_value()) {
                    // const auto deleteButton = btnDelete.value();
                    const auto reportButton = btnReport.value();

                    std::cerr << "Hier" << std::endl;

                    int nameWidth = 115;
                    int nameHeight = 37;
                    int padding = 10;

                    const Type::Rect cropRegion = {
                        reportButton.X - (nameWidth + padding), reportButton.Y, nameWidth, nameHeight
                    };
                    const Type::Rect imageRegion = {0, 62, 491, 268};

                    int calculatedHeight = gift.height - (imageRegion.Height + imageRegion.Y);
                    int calculatedWidth = (ProfileWidth - FriendsListWidth);
                    calculatedWidth += 5;
                    int calculatedY = gift.height - calculatedHeight;

                    auto nameCrop = gift.crop(cropRegion.X, cropRegion.Y - 16, cropRegion.Width, cropRegion.Height);
                    auto textCrop = gift.crop(0, calculatedY, calculatedWidth, calculatedHeight);

                    auto messageText = core->GetInteraction<ImageReader>().ImageToText(textCrop, 0.8f, true);
                    auto nameText = core->GetInteraction<ImageReader>().ImageToText(nameCrop, 0.8f, true);

                    GiftSender sender{
                        .Sender = nameText.value_or("Unknow"), .Message = messageText.value_or("No text found")
                    };;

                    return sender;
                } else {
                    std::cerr << "Cant btnDelete or btnReport" << std::endl;
                }
            } else {
                std::cerr << "Found it" << std::endl;
            }
        }

        return std::nullopt;
    }
}
