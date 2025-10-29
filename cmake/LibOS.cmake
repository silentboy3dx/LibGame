include(FetchContent)

FetchContent_Declare(
        LibOS
        GIT_REPOSITORY https://github.com/silentboy3dx/LibOS.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(LibOS)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${libos_SOURCE_DIR}/include
)

message(STATUS "Linking LibOS using includes ${libos_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} PRIVATE LibOS)
