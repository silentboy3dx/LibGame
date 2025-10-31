cmake_minimum_required(VERSION 4.0)
project(LibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBGRAPHICS_ENABLE_TESTS OFF CACHE BOOL "Disable LibGraphics tests")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Bouw de executable
add_executable(${PROJECT_NAME}
        include/LibGame/BaseInteraction.hpp
        include/LibGame/io/Keyboard.hpp
        include/LibGame/io/Mouse.hpp

        include/LibGame/detect/DArgs.hpp
        include/LibGame/detect/Detector.hpp
        include/LibGame/detect/DResult.hpp

        include/LibGame/Interactions.hpp
        include/LibGame/LibGame.hpp

        src/detect/Detector.cpp

        src/Interactions.cpp
        src/main.cpp

        src/io/Mouse.cpp
        src/io/Keyboard.cpp
        include/LibGame/detect/Detector.hpp
        include/LibGame/detect/DResult.hpp


)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(LibGraphics)
include(LibScreenshots)
include(LibIO)
include(LibOS)