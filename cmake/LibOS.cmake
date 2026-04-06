if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/LibOS")
endif()

find_package(LibOS REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE LibOS::LibOS)