#include "LibGame/module/Gift.hpp"

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
        return ClickIfVisible("gift/button_my_gifts.png");
    }

    std::optional<GiftSender> Gift::GetLatestGiftFromProfile() {
        const auto profile = core->GetInteraction<Profile>();

        profile.OpenMyProfile();

        GoToMyGifts();

        auto result = ReadLastestGift();

        profile.CloseMyProfile();

        // open profile
        // click my gifts
        // read gift
        // close profile
        // return gift sender info

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

                    const Type::Rect cropRegion = {reportButton.X - (nameWidth + padding), reportButton.Y, nameWidth, nameHeight};
                    const Type::Rect imageRegion = {0, 62, 491, 268};

                    // std::vector<Type::Rect> redaction = {
                    //     /* Report button */
                    //     {reportButton.X, reportButton.Y, reportButton.Width, reportButton.Height},
                    //     /* Delete button */
                    //     {deleteButton.X, deleteButton.Y, deleteButton.Width, deleteButton.Height},
                    //     /* Name */
                    //     {reportButton.X - (nameWidth + padding), reportButton.Y, nameWidth, nameHeight},
                    //     /* Gift image */
                    //     imageRegion
                    // };

                    int calculatedHeight = gift.height - (imageRegion.Height + imageRegion.Y);
                    int calculatedWidth = (ProfileWidth - FriendsListWidth); calculatedWidth += 5;
                    int calculatedY = gift.height - calculatedHeight;

                    auto nameCrop = gift.crop(cropRegion.X, cropRegion.Y - 16, cropRegion.Width, cropRegion.Height);
                    auto textCrop = gift.crop(0, calculatedY, calculatedWidth,   calculatedHeight);

                    auto messageText = core->GetInteraction<ImageReader>().ImageToText(textCrop, 0.8f, true);
                    auto nameText = core->GetInteraction<ImageReader>().ImageToText(nameCrop, 0.8f, true);

                    GiftSender sender{.Sender = nameText.value_or("Unknow"), .Message = messageText.value_or("No text found")};;

                    return sender;
                }

                // gift.show();
                // mouse->MoveTo(seperator.X, seperator.Y);
            }
        }

        return std::nullopt;
    }
}
