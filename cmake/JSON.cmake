find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        nlohmann_json::nlohmann_json
)
