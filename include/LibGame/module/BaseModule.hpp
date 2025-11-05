#pragma once

#include <X11/Xlib.h>

#include "LibGame/Interactions.hpp"
#include "LibGame/detect/Detector.hpp"
#include "LibGame/asset/Assets.hpp"

#include "LibGame/io/Keyboard.hpp"
#include "LibGame/io/Mouse.hpp"
#include "LibGame/io/Screenshot.hpp"

#include <thread>
#include <chrono>

using namespace LibGame::Io;
using namespace LibGame::Detect;
using namespace LibGame::Asset;

namespace LibGame::Module {
    class BaseModule : public BaseInteraction {
    public:
        explicit BaseModule(Interactions *core) : BaseInteraction(core) {
            screenshot = core ? &core->GetInteraction<Screenshot>() : nullptr;
            keyboard = core ? &core->GetInteraction<Keyboard>() : nullptr;
            mouse = core ? &core->GetInteraction<Mouse>() : nullptr;

            detector = core ? &core->GetInteraction<Detector>() : nullptr;
            assets = core ? &core->GetInteraction<Assets>() : nullptr;
        }

        ~BaseModule() override = default;



    protected:
        Assets *assets = nullptr;
        Detector *detector = nullptr;
        Keyboard* keyboard = nullptr;
        Screenshot* screenshot = nullptr;
        Mouse* mouse = nullptr;

        static void sleepms(int ms) {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
    };
}
