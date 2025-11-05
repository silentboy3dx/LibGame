#include <cstdio>
#include <thread>
#include <vector>
// #include <opencv2/core/matx.hpp>

#include <iostream>

#include "LibGame/Interactions.hpp"
#include "LibGame/module/Clothing.hpp"


using namespace LibGame;
using namespace LibGame::Module;

int main() {
    printf("Hello World!\n");

    // Get the Interactions instance
    auto &interactions = Interactions::GetInstance();

    interactions.GetInteraction<Assets>().setAssetType(AssetType::TYPE_2K);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    interactions.GetInteraction<Clothing>().TakeAllOff();


    // interactions.RegisterInteraction<Mouse>();
    // interactions.RegisterInteraction<Keyboard>();
    //
    // // Use the mouse interaction
    // interactions.GetInteraction<Mouse>().Click();
    //
    // Interactions::GetInstance().GetInteraction<Keyboard>().Typewrite("Hello, World!");
    // interactions.GetInteraction<Keyboard>().Typewrite("Hello, World!");

    // auto result = interactions.GetInteraction<Detect::Detector>().Take();

    // for (int i = 0; i < 1he0; i++) {
    //     if (interactions.IsGameInForeground()) {
    //         std::cout << "Game is in foreground" << std::endl;
    //     } else {
    //         std::cout << "Game is not in foreground" << std::endl;
    //     }
    //
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }


    return 0;
}
