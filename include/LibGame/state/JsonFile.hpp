#pragma once

#include "LibGame/state/BaseState.hpp"

#include <nlohmann/json.hpp>
#include <thread>
#include <mutex>

namespace LibGame::State {
    class JsonFile final : public BaseState {
    public:
        JsonFile();
        ~JsonFile() override;

        void Set(const std::string& key, const std::any& value) override;
        std::any Get(const std::string& key) override;
        bool Has(const std::string& key) override;
        void Remove(const std::string& key) override;
        std::string ToJson() override;

    private:
        void LoadDataFromFile();
        void SaveDataToFile() const;
        void StartPollingThread();
        void RunPollingThread();

        static nlohmann::json AnyToJson(const std::any& value);
        static std::any JsonToAny(const nlohmann::json& json);

        std::string _dataFilePath;
        bool _didChange = false;
        nlohmann::json _jsonData;
        std::thread _pollingThread;
        std::mutex _dataMutex;
        bool _loop = true;
    };
}
