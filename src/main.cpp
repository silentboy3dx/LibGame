#include "LibGame/LibGame.hpp"
#include "LibGame/io/Clipboard.hpp"

#include "LibGame/action/primary/SlowDanceStatus.hpp"

#include <thread>
#include <chrono>

#include "LibGame/action/primary/DanceStatus.hpp"
#include "LibGame/action/primary/IdlePrimaryStatus.hpp"
#include "LibGame/action/secondary/MovementSpeedSecondaryStatus.hpp"
#include "LibGame/action/secondary/NakedSecondaryStatus.hpp"
#include "LibGame/action/secondary/StraponSecondaryStatus.hpp"

using namespace LibGame;
using namespace LibGame::Action::Primary;
using namespace LibGame::Action::Secondary;
using namespace LibGame::Module;
using namespace LibGame::Io;

int main() {

    auto &interactions = Interactions::GetInstance();
    auto &moderation = interactions.GetInteraction<Moderation>();

    // std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //
    // interactions.GetInteraction<Clothing>().UnDressAll();
    //
    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //
    // interactions.GetInteraction<Clothing>().DressAll();
    // auto ctx = interactions.GetInteraction<Context>();

    //
    // // Primaire actie
    // ctx.SetPrimaryAction<SlowDanceStatus>(SlowDanceStatus::Type::Face2Face, "Alice");
    //
    // // Secundaire actie
    // ctx.AddSecondaryAction<EatStatus>(EatStatus::Type::Pizza);
    //
    // std::cout << ctx;

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // interactions.GetInteraction<Clothing>().DressAll();

    interactions.GetInteraction<Context>().before("=== Start ===")
       // .SetPrimaryAction<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle3)
       // .SetPrimaryAction<DanceStatus>(DanceStatus::Type::Dance7)
       // .AddSecondaryAction<EatStatus>(EatStatus::Type::Pizza)
       // .AddSecondaryAction<MovementSpeedSecondaryStatus>(MovementSpeedSecondaryStatus::Type::Running)
       // .AddSecondaryAction<StraponSecondaryStatus>(StraponSecondaryStatus::Type::Penis)
       // .AddSecondaryAction<NakedSecondaryStatus>(NakedSecondaryStatus::Type::Undressed)
       .add("Mood", "Happy")
       .after("=== End ===");


    // interactions.GetInteraction<Strapon>().Penis();
    // interactions.GetInteraction<Strapon>().Toy1();
    // interactions.GetInteraction<Strapon>().Toy2();
    interactions.GetInteraction<Movement>().Run();

    // ctx.SetPrimaryAction<IdlePrimaryStatus>(IdlePrimaryStatus::Type::Idle4);

    std::cout << interactions.GetInteraction<Context>() << "\n";

    return 0;
}