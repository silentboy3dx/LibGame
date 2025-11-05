cmake_minimum_required(VERSION 4.0)
project(LibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBGRAPHICS_ENABLE_TESTS OFF CACHE BOOL "Disable LibGraphics tests")
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
        include/LibGame/module/Clothing.hpp


        src/modules/Clothing.cpp


        src/detect/Detector.cpp

        src/Interactions.cpp

        src/asset/Assets.cpp

        src/io/Screenshot.cpp
        src/io/Keyboard.cpp
        src/io/Mouse.cpp

        src/main.cpp
        include/LibGame/misc/Point.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(LibGraphics)
include(LibScreenshots)
include(LibIO)
include(LibOS)