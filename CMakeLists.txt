cmake_minimum_required(VERSION 4.0)
project(LibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBGRAPHICS_ENABLE_TESTS OFF CACHE BOOL "Disable LibGraphics tests")
#set(WAYLAND OFF CACHE BOOL "Disable Wayland portal" FORCE)
#set(PIPEWIRE ON CACHE BOOL "Enable PipeWire" FORCE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# add_executable
add_library(${PROJECT_NAME}

        include/LibGame/io/Screenshot.hpp
        include/LibGame/io/Clipboard.hpp
        include/LibGame/io/Keyboard.hpp
        include/LibGame/io/Mouse.hpp

        include/LibGame/detect/DArgs.hpp
        include/LibGame/detect/Detector.hpp
        include/LibGame/detect/DResult.hpp

        include/LibGame/asset/Assets.hpp

        include/LibGame/Interactions.hpp
        include/LibGame/LibGame.hpp

        include/LibGame/action/primary/IdlePrimaryStatus.hpp
        include/LibGame/action/primary/SlowDanceStatus.hpp
        include/LibGame/action/primary/DanceStatus.hpp
        include/LibGame/action/primary/ActionStatus.hpp

        include/LibGame/action/secondary/MovementSpeedSecondaryStatus.hpp
        include/LibGame/action/secondary/StraponSecondaryStatus.hpp
        include/LibGame/action/secondary/PartnerSecondaryStatus.hpp
        include/LibGame/action/secondary/NakedSecondaryStatus.hpp

        include/LibGame/module/ImageReader.hpp
        include/LibGame/module/Moderation.hpp
        include/LibGame/module/SexActions.hpp
        include/LibGame/module/BaseModule.hpp
        include/LibGame/module/Slowdance.hpp
        include/LibGame/module/Interface.hpp
        include/LibGame/module/Clothing.hpp
        include/LibGame/module/Movement.hpp
        include/LibGame/module/Friends.hpp
        include/LibGame/module/Context.hpp
        include/LibGame/module/Strapon.hpp
        include/LibGame/module/Profile.hpp
        include/LibGame/module/Actions.hpp
        include/LibGame/module/Dances.hpp
        include/LibGame/module/Camera.hpp
        include/LibGame/module/Chat.hpp
        include/LibGame/module/Idle.hpp
        include/LibGame/module/Item.hpp
        include/LibGame/module/Gift.hpp

        include/LibGame/misc/KvStore.hpp
        include/LibGame/misc/Point.hpp

        include/LibGame/state/BaseState.hpp
        include/LibGame/state/JsonFile.hpp

        src/modules/ImageReader.cpp
        src/modules/Moderation.cpp
        src/modules/SexActions.cpp
        src/modules/Slowdance.cpp
        src/modules/Interface.cpp
        src/modules/Movement.cpp
        src/modules/Clothing.cpp
        src/modules/Profile.cpp
        src/modules/Actions.cpp
        src/modules/Context.cpp
        src/modules/Strapon.cpp
        src/modules/Friends.cpp
        src/modules/Dances.cpp
        src/modules/Camera.cpp
        src/modules/Chat.cpp
        src/modules/Idle.cpp
        src/modules/Item.cpp
        src/modules/Gift.cpp

        src/detect/Detector.cpp
        src/asset/Assets.cpp

        src/action/primary/IdlePrimaryStatus.cpp
        src/action/primary/SlowDanceStatus.cpp
        src/action/primary/ActionStatus.cpp
        src/action/primary/DanceStatus.cpp

        src/action/secondary/MovementSpeedSecondaryStatus.cpp
        src/action/secondary/StraponSecondaryStatus.cpp
        src/action/secondary/PartnerSecondaryStatus.cpp
        src/action/secondary/NakedSecondaryStatus.cpp

        src/state/JsonFile.cpp

        src/io/Screenshot.cpp
        src/io/Clipboard.cpp
        src/io/Keyboard.cpp
        src/io/Mouse.cpp

        src/Interactions.cpp
        src/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WINDOWS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_LINUX)
endif()

include(LibGraphics)
include(LibScreenshots)
include(LibIO)
include(LibOS)