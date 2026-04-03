include(FetchContent)

FetchContent_Declare(LibScreenshots
        GIT_REPOSITORY https://github.com/johnnymast/LibScreenshots.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibScreenshots)
target_link_libraries(LibGame PUBLIC LibScreenshots)
