include(FetchContent)

FetchContent_Declare(LibIO
        GIT_REPOSITORY https://github.com/johnnymast/LibIO.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibIO)

target_link_libraries(LibGame PRIVATE LibIO)