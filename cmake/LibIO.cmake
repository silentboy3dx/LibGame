find_package(LibIO REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        LibIO::LibIO
)

target_link_libraries(LibGame PUBLIC LibIO::LibIO)
