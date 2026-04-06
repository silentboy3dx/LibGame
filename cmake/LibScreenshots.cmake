find_package(LibGraphics REQUIRED)
find_package(LibScreenshots REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        LibScreenshots::LibScreenshots
)
