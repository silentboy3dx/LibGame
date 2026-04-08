if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/LibOS")
endif()

find_package(LibOS REQUIRED)