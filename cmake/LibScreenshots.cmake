include(FetchContent)

FetchContent_Declare(LibScreenshots
        GIT_REPOSITORY https://github.com/johnnymast/LibScreenshots.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibScreenshots)

target_link_libraries(${PROJECT_NAME} PRIVATE LibScreenshots)

get_target_property(LIBSCREENSHOTS_INCLUDE_DIRS LibScreenshots INTERFACE_INCLUDE_DIRECTORIES)
if(NOT LIBSCREENSHOTS_INCLUDE_DIRS)
    set(LIBSCREENSHOTS_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../LibScreenshots/include")
endif()
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBSCREENSHOTS_INCLUDE_DIRS})

