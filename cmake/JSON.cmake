include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(nlohmann_json)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
