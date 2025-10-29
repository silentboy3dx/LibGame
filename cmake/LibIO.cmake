include(FetchContent)

FetchContent_Declare(LibIO
        GIT_REPOSITORY https://github.com/johnnymast/LibIO.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibIO)

target_link_libraries(${PROJECT_NAME} PRIVATE LibIO)

get_target_property(LIBIO_INCLUDE_DIRS LibIO INTERFACE_INCLUDE_DIRECTORIES)

if(NOT LIBIO_INCLUDE_DIRS)
    set(LIBIO_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../io/include")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${LIBIO_INCLUDE_DIRS})