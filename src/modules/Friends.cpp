#include "LibGame/module/Friends.hpp"

#include "LibGame/module/Profile.hpp"
#include "LibGame/module/ImageReader.hpp"

using Color::BackgroundScanner;
using Color::Information;

namespace LibGame::Module {

    std::string Friends::stripAndTrim(const std::string& input) {
        std::string s = input;

        // strip prefix "| " als die er staat
        if (s.rfind("| ", 0) == 0) {
            s = s.substr(2);
        }

        // trim whitespace links en rechts
        const auto start = std::find_if_not(s.begin(), s.end(), ::isspace);
        const auto end   = std::find_if_not(s.rbegin(), s.rend(), ::isspace).base();

        if (start >= end) return ""; // alles was whitespace
        return std::string(start, end);
    }


    std::vector<std::string> Friends::GetOnlineFriends() {
        std::vector<std::string> friends;

        auto profile = core->GetInteraction<Profile>();
        profile.OpenMyProfile();

        const auto screenshot = core->GetInteraction<Screenshot>().Take();


        if (screenshot.image.isValid()) {

            const auto result = GetAsset("friends/label_online_friends.png",
                                         DArgs{.grayscale = true, .confidence = 0.99f});


            if (result.has_value()) {
                const auto label = result.value();
                const int steps = (FRIENDS_MAX_HEIGHT - LABEL_ONLINE_FRIENDS_TOP_OFFSET) / FRIENDS_NAME_HEIGHT;

                Image list = screenshot.image.crop(label.X, (label.Y + label.Height), FRIENDS_LIST_WIDTH,
                                                   FRIENDS_MAX_HEIGHT);

                int x = 15;
                int y = 0;

                for (int step = 0; step < steps; step += 1) {

                    int offset = BackgroundScanner::background_color_change_down(
                        list, x, y, FRIENDS_NAME_HEIGHT, false
                    );

                    if (offset > -1) {
                        std::array<uint8_t, 3> pixels = list.getRGB(x, y + offset+1);

                        int r = pixels[0], g = pixels[1], b = pixels[2];

                        if (Information::is_white(r, g, b, 5)) {

                            int yy = (label.Y + label.Height) + y;
                            auto name = screenshot.image.crop((label.X + x) - 14, yy, FRIENDS_LIST_WIDTH, FRIENDS_NAME_HEIGHT);

                            auto text = core->GetInteraction<ImageReader>().ImageToText(
                                name,
                                0.7f,
                                false
                            );

                            friends.push_back(stripAndTrim(text.value()));

                        } else {
                            step = steps;
                            break;
                        }
                        // mouse->MoveTo(label.X + x, label.Y + y + label.Height + offset);
                    }

                    y += FRIENDS_NAME_HEIGHT;
                }
            }
        }

        profile.CloseProfile();
        std::cout << "Found friends: " << friends.size() << std::endl;

        return friends;
    }

    bool Friends::isFriendOnline(const std::string &name) {
        auto friends = GetOnlineFriends();
        return std::find(friends.begin(), friends.end(), name) != friends.end();
    }
}
