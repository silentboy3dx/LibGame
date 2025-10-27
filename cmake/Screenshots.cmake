include(FetchContent)

FetchContent_Declare(LibScreenshots
        GIT_REPOSITORY https://github.com/johnnymast/LibScreenshots.git
        GIT_TAG master
)

FetchContent_MakeAvailable(LibScreenshots)

# Link Screenshots against LibScreenshots (the fetch content provides a target named LibScreenshots)
target_link_libraries(libtest PRIVATE LibScreenshots)

# Ensure LibScreenshots include directories are visible to Screenshots
get_target_property(LIBSCREENSHOTS_INCLUDE_DIRS LibScreenshots INTERFACE_INCLUDE_DIRECTORIES)
if(NOT LIBSCREENSHOTS_INCLUDE_DIRS)
    # Fallback in case LibScreenshots doesn't export include dirs
    set(LIBSCREENSHOTS_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../LibScreenshots/include")
endif()
target_include_directories(libtest PUBLIC ${LIBSCREENSHOTS_INCLUDE_DIRS})

