#include <cstdio>
#include <thread>

#include "LibGame/LibGame.hpp"



using namespace LibGame;
using namespace LibGame::Module;

int main() {
    printf("Hello World!\n");

    // Get the Interactions instance
    auto &interactions = Interactions::GetInstance();

    interactions.GetInteraction<Assets>().setAssetType(AssetType::TYPE_2K);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    // interactions.GetInteraction<Chat>().GoToLocal();
    // bool result = interactions.GetInteraction<Chat>().PlaceCursorInChat();
    // bool result = interactions.GetInteraction<Chat>().PressSend();
    interactions.GetInteraction<Dances>().Dance(47);
    // interactions.GetInteraction<Dances>().ScrollToTop();

    // interactions.GetInteraction<Chat>().WhipeChat();
    return 0;
}
