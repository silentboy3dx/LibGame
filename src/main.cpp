#include <cstdio>
#include <thread>
#include <vector>
// #include <opencv2/core/matx.hpp>

#include <iostream>

#include "LibGame/Interactions.hpp"

#include "LibGame/io/Mouse.hpp"
#include "LibGame/io/Keyboard.hpp"
#include "LibGame/LibGame.hpp"

using namespace LibGame;
using namespace LibGame::Io;

int main() {
    printf("Hello World!\n");

    // Get the Interactions instance
    auto &interactions = LibGame::Interactions::GetInstance();

    interactions.RegisterInteraction<Mouse>();
    interactions.RegisterInteraction<Keyboard>();

    // Use the mouse interaction
    interactions.GetInteraction<Mouse>().Click();

    Interactions::GetInstance().GetInteraction<Keyboard>().Typewrite("Hello, World!");

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
