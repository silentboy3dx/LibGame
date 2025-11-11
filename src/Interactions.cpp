#include "LibGame/Interactions.hpp"

#include "LibGame/io/Mouse.hpp"
#include "LibGame/io/Keyboard.hpp"

#include "LibGame/module/ImageReader.hpp"
#include "LibGame/module/Moderation.hpp"
#include "LibGame/module/SexActions.hpp"
#include "LibGame/module/Clipboard.hpp"
#include "LibGame/module/Slowdance.hpp"
#include "LibGame/module/Interface.hpp"
#include "LibGame/module/Clothing.hpp"
#include "LibGame/module/Movement.hpp"
#include "LibGame/module/Context.hpp"
#include "LibGame/module/Strapon.hpp"
#include "LibGame/module/Friends.hpp"
#include "LibGame/module/Profile.hpp"
#include "LibGame/module/Actions.hpp"
#include "LibGame/module/Dances.hpp"
#include "LibGame/module/Camera.hpp"
#include "LibGame/module/Chat.hpp"
#include "LibGame/module/Idle.hpp"
#include "LibGame/module/Item.hpp"
#include "LibGame/module/Gift.hpp"

#include <LibOS/LibOS.hpp>
#include <optional>

#include "LibGame/io/Screenshot.hpp"
#include "LibGame/state/JsonFile.hpp"

using namespace LibOS;
using namespace LibGame::Module;
using namespace LibGame::Io;

namespace LibGame {
    Interactions *Interactions::_instance = nullptr;

    Interactions::Interactions() {

        SetState(new JsonFile());

        RegisterInteraction<Mouse>();
        RegisterInteraction<Keyboard>();
        RegisterInteraction<Screenshot>();
        RegisterInteraction<Detector>();
        RegisterInteraction<Assets>();

        RegisterModule<ImageReader>();
        RegisterModule<Moderation>();
        RegisterModule<SexActions>();
        RegisterModule<Clipboard>();
        RegisterModule<Slowdance>();
        RegisterModule<Interface>();
        RegisterModule<Clothing>();
        RegisterModule<Movement>();
        RegisterModule<Actions>();
        RegisterModule<Profile>();
        RegisterModule<Context>();
        RegisterModule<Strapon>();
        RegisterModule<Friends>();
        RegisterModule<Dances>();
        RegisterModule<Camera>();
        RegisterModule<Chat>();
        RegisterModule<Idle>();
        RegisterModule<Item>();
        RegisterModule<Gift>();
    }

    Interactions &Interactions::GetInstance(){
        if (_instance == nullptr) {
            _instance = new Interactions();
        }
        return *_instance;
    }

    bool Interactions::IsGameInForeground() {
        if (const std::optional<WindowInfo> info = GetActiveWindow()) {
            return info->title == "3DXChat";
        }

        return false;
    }
}

