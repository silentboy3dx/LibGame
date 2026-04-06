if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/LibOS")
endif()

find_package(LibIO REQUIRED)

target_link_libraries(LibGame PRIVATE LibIO::LibIO)
