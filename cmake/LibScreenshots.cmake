if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/LibScreenshots")
endif()

find_package(LibGraphics REQUIRED)
find_package(LibScreenshots REQUIRED)

target_link_libraries(LibGame
        PUBLIC
        LibScreenshots::LibScreenshots
)
