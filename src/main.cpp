

#include <cstdio>
#include <thread>
#include <vector>
#include <opencv2/core/matx.hpp>

#include "LibGame/Interactions.hpp"
#include "LibGame/Mouse.hpp"


using namespace LibGame;

int main() {
    printf("Hello World!\n");

    // Get the Interactions instance
    auto& interactions = LibGame::Interactions::GetInstance();

    interactions.RegisterInteraction<LibGame::Mouse>();

    // Use the mouse interaction
    interactions.GetInteraction<LibGame::Mouse>().Click();

    for (int i = 0; i < 10; i++) {

        if (interactions.IsGameInForeground()) {
            std::cout << "Game is in foreground" << std::endl;
        } else {
            std::cout << "Game is not in foreground" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }



    return 0;
}
