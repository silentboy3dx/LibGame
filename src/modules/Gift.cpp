#include "LibGame/module/Gift.hpp"

#include <LibGraphics/type/Rect.hpp>

#include "LibGame/misc/Point.hpp"
#include "LibGame/module/Friends.hpp"
#include "LibGame/module/ImageReader.hpp"
#include "LibGame/module/Profile.hpp"

using Type::Rect;

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

    std::optional<GiftSender> Gift::ReadLastestGift() {



        const auto screenshot = core->GetInteraction<Screenshot>().Take();

        const auto btn_result = GetAsset("gift/button_my_gifts_highlighted.png",
                                                 DArgs{.grayscale = false, .confidence = 0.99f, .match_target = screenshot.image});

        GiftSender sender {.Message = "No message found"};

        if (screenshot.image.isValid() && btn_result.has_value()) {
            const auto giftbutton = btn_result.value();
            const auto innerToLeft = Point(giftbutton.X - 192, giftbutton.Y + giftbutton.Height);

            if (auto const seperator_result = GetAsset("gift/gift_seperator.png"); seperator_result.has_value()) {
                const auto seperator = seperator_result.value();


                 auto gift = screenshot.image.crop(innerToLeft.X, innerToLeft.Y, PROFILE_WINDOW_WIDTH - FRIENDS_LIST_WIDTH, seperator.Y - innerToLeft.Y);

                 auto const btnDelete = GetAsset("gift/button_delete.png",
                                                 DArgs{.grayscale = true, .confidence = 0.99f, .match_target = gift});


                 if (btnDelete.has_value()) {
                     const auto button = btnDelete.value();

                     /**
                      * We will redact both the gift image and the delete button so that
                      * we have a better ocr result.
                      */
                     std::vector<Type::Rect> decations = {
                         {button.X, button.Y, button.Width, button.Height}, /* Delete button */
                         {0, 62, 491, 268} /* Gift image */
                     };

                     gift.redact(decations);

                     auto result = core->GetInteraction<ImageReader>().ImageToText(gift, 0.8f, true);

                     GiftSender sender{.Message = result.value_or("No text found")};;

                     return sender;
                 }

                // gift.show();
                // mouse->MoveTo(seperator.X, seperator.Y);
            }
        }

        return std::nullopt;
    }


}
