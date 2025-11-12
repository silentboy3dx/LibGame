#include "LibGame/LibGame.hpp"

using namespace LibGame::Module;

int main() {

    auto &interactions = LibGame::Interactions::GetInstance();
    interactions.GetInteraction<Dances>().Dance(12);

    return 0;
}