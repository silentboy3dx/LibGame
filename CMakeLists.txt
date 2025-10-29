cmake_minimum_required(VERSION 3.10)
project(LibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBGRAPHICS_ENABLE_TESTS OFF CACHE BOOL "Disable LibGraphics tests")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Bouw de executable
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Interactions.cpp
        include/LibGame/LibGame.hpp
        include/LibGame/Interactions.hpp
        include/LibGame/Mouse.hpp
        include/LibGame/InteractionBase.hpp
        include/LibGame/io/Mouse.cpp
        include/LibGame/io/Mouse.hpp
        include/LibGame/io/Keyboard.cpp
        include/LibGame/io/Keyboard.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(LibGraphics)
include(LibScreenshots)
include(LibIO)
include(LibOS)