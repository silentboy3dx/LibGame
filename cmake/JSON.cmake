find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        nlohmann_json::nlohmann_json
)
