include(FetchContent)

FetchContent_Declare(LibOS
        GIT_REPOSITORY https://github.com/silentboy3dx/LibOS.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibOS)

target_link_libraries(${PROJECT_NAME} PRIVATE LibOS)

#get_target_property(LIBIO_INCLUDE_DIRS LibIO INTERFACE_INCLUDE_DIRECTORIES)

if(NOT LIBIO_INCLUDE_DIRS)
    set(LIBIO_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../LibOS/include")
endif()
target_include_directories(${PROJECT_NAME} PRIVATE LibOS)