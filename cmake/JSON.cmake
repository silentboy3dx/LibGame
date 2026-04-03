if(NOT TARGET nlohmann_json::nlohmann_json)
    include(FetchContent)

    FetchContent_Declare(
            nlohmann_json
            GIT_REPOSITORY https://github.com/nlohmann/json.git
            GIT_TAG v3.11.3
    )

    FetchContent_MakeAvailable(nlohmann_json)
    target_link_libraries(LibGame PRIVATE nlohmann_json::nlohmann_json)
endif()

