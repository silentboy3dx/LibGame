

#include <cstdio>
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

    return 0;
}
