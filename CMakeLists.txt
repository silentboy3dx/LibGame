cmake_minimum_required(VERSION 4.0)
project(LibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBGRAPHICS_ENABLE_TESTS OFF CACHE BOOL "Disable LibGraphics tests")
#set(WAYLAND OFF CACHE BOOL "Disable Wayland portal" FORCE)
#set(PIPEWIRE ON CACHE BOOL "Enable PipeWire" FORCE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_executable(${PROJECT_NAME}
        include/LibGame/io/Screenshot.hpp
        include/LibGame/io/Keyboard.hpp
        include/LibGame/io/Mouse.hpp

        include/LibGame/detect/DArgs.hpp
        include/LibGame/detect/Detector.hpp
        include/LibGame/detect/DResult.hpp

        include/LibGame/asset/Assets.hpp

        include/LibGame/Interactions.hpp
        include/LibGame/LibGame.hpp


        include/LibGame/module/BaseModule.hpp
        include/LibGame/module/Clipboard.hpp
        include/LibGame/module/Clothing.hpp
        include/LibGame/module/Actions.hpp
        include/LibGame/module/Dances.hpp
        include/LibGame/module/Camera.hpp
        include/LibGame/module/Chat.hpp

        src/modules/Clothing.cpp
        src/modules/Actions.cpp
        src/modules/Chat.cpp
        src/modules/Dances.cpp

        src/detect/Detector.cpp

        src/Interactions.cpp

        src/asset/Assets.cpp

        src/io/Screenshot.cpp
        src/io/Keyboard.cpp
        src/io/Mouse.cpp

        src/main.cpp
        include/LibGame/misc/Point.h
        src/modules/Camera.cpp
        src/modules/Chat.cpp
        src/modules/Clipboard.cpp


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