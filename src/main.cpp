#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include "LibGame/LibGame.hpp"

using namespace LibGame;
using namespace LibGame::Module;

#include <thread>
#include <chrono>

using namespace LibGame;
using namespace LibGame::Module;

int main() {
    printf("=== Moderation Module Tests ===\n\n");

    auto &interactions = Interactions::GetInstance();
    auto &moderation = interactions.GetInteraction<Moderation>();

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    const std::optional<GiftSender> result = interactions.GetInteraction<Gift>().GetLatestGiftFromProfile();

    if (result.has_value()) {

        std::cout << "Gift OCR Result: " << result->Message << std::endl;
    } else {
        std::cout << "No gift found or OCR failed." << std::endl;
    }

    return 0;
}