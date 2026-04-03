include(FetchContent)

# Fetch LibGraphics
FetchContent_Declare(LibGraphics
        GIT_REPOSITORY https://github.com/johnnymast/LibGraphics.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibGraphics)

# Link LibGraphics to LibGame
target_link_libraries(LibGame
        PUBLIC
        LibGraphics
)
