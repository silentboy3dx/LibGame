#include "LibGame/state/JsonFile.hpp"

#include <fstream>
#include <map>
#include <filesystem>
#include <thread>
#include <chrono>
#include <mutex>
#include <any>
#include <vector>

#pragma warning("Move GetEnvString to LibOS")

namespace LibGame::State {

    // ------------------------------------------------------------
    // Portable environment variable reader (Windows + Linux/macOS)
    // ------------------------------------------------------------
    static std::string GetEnvString(const char* name) {
    #if defined(_WIN32)
        char* buffer = nullptr;
        size_t size = 0;

        if (_dupenv_s(&buffer, &size, name) == 0 && buffer != nullptr) {
            std::string value(buffer);
            free(buffer);
            return value;
        }
        return "";
    #else
        const char* val = std::getenv(name);
        return val ? std::string(val) : "";
    #endif
    }

    // ------------------------------------------------------------
    // Constructor / Destructor
    // ------------------------------------------------------------

    JsonFile::JsonFile() {
        std::string dataPathEnv = GetEnvString("LIBGAME_DATA_PATH");

        if (!dataPathEnv.empty()) {
            _dataFilePath = dataPathEnv + "/data.json";
        } else {
            _dataFilePath = "./data.json";
        }

        LoadDataFromFile();
        StartPollingThread();
    }

    JsonFile::~JsonFile() {
        _loop = false;
        if (_pollingThread.joinable()) {
            _pollingThread.join();
        }
    }

    // ------------------------------------------------------------
    // Public API
    // ------------------------------------------------------------

    void JsonFile::Set(const std::string &key, const std::any &value) {
        std::lock_guard<std::mutex> lock(_dataMutex);

        _didChange = true;
        _jsonData[key] = AnyToJson(value);
        SaveDataToFile();
    }

    std::any JsonFile::Get(const std::string &key) {
        std::lock_guard<std::mutex> lock(_dataMutex);

        if (!_jsonData.contains(key)) {
            return std::any();
        }

        return JsonToAny(_jsonData[key]);
    }

    bool JsonFile::Has(const std::string &key) {
        std::lock_guard<std::mutex> lock(_dataMutex);
        return _jsonData.contains(key);
    }

    void JsonFile::Remove(const std::string &key) {
        std::lock_guard<std::mutex> lock(_dataMutex);

        if (_jsonData.contains(key)) {
            _jsonData.erase(key);
            _didChange = true;
        }
    }

    std::string JsonFile::ToJson() {
        std::lock_guard<std::mutex> lock(_dataMutex);
        return _jsonData.dump(4);
    }

    // ------------------------------------------------------------
    // File IO
    // ------------------------------------------------------------

    void JsonFile::LoadDataFromFile() {
        try {
            std::ifstream file(_dataFilePath);
            if (file.is_open()) {
                file >> _jsonData;
            } else {
                _jsonData = nlohmann::json::object();
            }
        } catch (const nlohmann::json::exception &) {
            _jsonData = nlohmann::json::object();
        }
    }

    void JsonFile::SaveDataToFile() const {
        try {
            auto path = std::filesystem::path(_dataFilePath);
            std::filesystem::create_directories(path.parent_path());

            std::ofstream file(_dataFilePath);
            if (file.is_open()) {
                file << _jsonData.dump(4);
            }
        } catch (const std::exception &) {
            // swallow errors silently
        }
    }

    // ------------------------------------------------------------
    // Polling thread
    // ------------------------------------------------------------

    void JsonFile::StartPollingThread() {
        _pollingThread = std::thread([this]() {
            this->RunPollingThread();
        });
    }

    void JsonFile::RunPollingThread() {
        while (_loop) {
            {
                std::lock_guard<std::mutex> lock(_dataMutex);
                if (_didChange) {
                    SaveDataToFile();
                    _didChange = false;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }

    // ------------------------------------------------------------
    // Any → JSON
    // ------------------------------------------------------------

    nlohmann::json JsonFile::AnyToJson(const std::any &value) {
        try {
            // Integer types
            if (value.type() == typeid(int)) {
                return std::any_cast<int>(value);
            } else if (value.type() == typeid(long)) {
                return static_cast<int>(std::any_cast<long>(value));
            } else if (value.type() == typeid(long long)) {
                return std::any_cast<long long>(value);
            } else if (value.type() == typeid(short)) {
                return static_cast<int>(std::any_cast<short>(value));
            } else if (value.type() == typeid(unsigned int)) {
                return static_cast<int>(std::any_cast<unsigned int>(value));
            } else if (value.type() == typeid(unsigned long)) {
                return static_cast<int>(std::any_cast<unsigned long>(value));
            } else if (value.type() == typeid(unsigned short)) {
                return static_cast<int>(std::any_cast<unsigned short>(value));
            }

            // Float types
            else if (value.type() == typeid(double)) {
                return std::any_cast<double>(value);
            } else if (value.type() == typeid(float)) {
                return std::any_cast<float>(value);
            }

            // Boolean
            else if (value.type() == typeid(bool)) {
                return std::any_cast<bool>(value);
            }

            // String types
            else if (value.type() == typeid(std::string)) {
                return std::any_cast<std::string>(value);
            } else if (value.type() == typeid(const char *)) {
                return std::string(std::any_cast<const char *>(value));
            }

            // Vector<int>
            else if (value.type() == typeid(std::vector<int>)) {
                auto vec = std::any_cast<std::vector<int>>(value);
                return nlohmann::json(vec);
            }

            // Vector<string>
            else if (value.type() == typeid(std::vector<std::string>)) {
                auto vec = std::any_cast<std::vector<std::string>>(value);
                return nlohmann::json(vec);
            }

            // Map<string, int>
            else if (value.type() == typeid(std::map<std::string, int>)) {
                auto map = std::any_cast<std::map<std::string, int>>(value);
                return nlohmann::json(map);
            }

            // Map<string, string>
            else if (value.type() == typeid(std::map<std::string, std::string>)) {
                auto map = std::any_cast<std::map<std::string, std::string>>(value);
                return nlohmann::json(map);
            }

            return nullptr;
        } catch (const std::bad_any_cast &) {
            return nullptr;
        }
    }

    // ------------------------------------------------------------
    // JSON → Any
    // ------------------------------------------------------------

    std::any JsonFile::JsonToAny(const nlohmann::json &json) {
        try {
            if (json.is_null()) {
                return std::any();
            } else if (json.is_boolean()) {
                return json.get<bool>();
            } else if (json.is_number_float()) {
                return json.get<double>();
            } else if (json.is_number_integer()) {
                return json.get<int>();
            } else if (json.is_string()) {
                return json.get<std::string>();
            } else if (json.is_array()) {
                std::vector<std::string> result;
                for (const auto &item : json) {
                    if (item.is_string()) {
                        result.push_back(item.get<std::string>());
                    } else {
                        result.push_back(item.dump());
                    }
                }
                return result;
            } else if (json.is_object()) {
                std::map<std::string, std::string> result;
                for (auto it = json.begin(); it != json.end(); ++it) {
                    if (it.value().is_string()) {
                        result[it.key()] = it.value().get<std::string>();
                    } else {
                        result[it.key()] = it.value().dump();
                    }
                }
                return result;
            }

            return std::any();
        } catch (const nlohmann::json::exception &) {
            return std::any();
        }
    }

} // namespace LibGame::State
