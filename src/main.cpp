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

    // interactions.GetInteraction<Idle>().IdleOne();
    // interactions.GetInteraction<Idle>().IdleTwo();
    // interactions.GetInteraction<Idle>().IdleThree();
    // interactions.GetInteraction<Idle>().IdleFour();
    // interactions.GetInteraction<Idle>().IdleFive();
    // interactions.GetInteraction<Idle>().IdleSix();

    return 0;
}
