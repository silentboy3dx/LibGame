message(STATUS "  🔨 Linking LibIO")

if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/LibIO")
endif()

find_package(LibIO REQUIRED)
