include(FetchContent)

FetchContent_Declare(LibIO
        GIT_REPOSITORY https://github.com/johnnymast/LibIO.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibIO)

# Link against LibIO
target_link_libraries(libtest PRIVATE LibIO)

# Expose LibIO headers to libtest
get_target_property(LIBIO_INCLUDE_DIRS LibIO INTERFACE_INCLUDE_DIRECTORIES)
if(NOT LIBIO_INCLUDE_DIRS)
    set(LIBIO_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../io/include")
endif()
target_include_directories(libtest PRIVATE ${LIBIO_INCLUDE_DIRS})