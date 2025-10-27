cmake_minimum_required(VERSION 3.10)
project(LibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(WAYLAND "Enable Wayland support via DBus portal" OFF)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Bouw de executable
add_executable(${PROJECT_NAME}
        src/main.cpp
)

include(LibGraphics)
include(LibScreenshots)
include(LibIO)