#include "LibGame/module/Moderation.hpp"
#include <chrono>
#include <nlohmann/json.hpp>

namespace LibGame::Module {

    Moderation::Moderation(Interactions *core) : BaseModule(core) {
        _state = core->GetState();

        // DON'T initialize empty collections - let GetTimeouts/GetBlockList handle that
        // This way existing data from file is preserved
    }

    void Moderation::AddTimeout(const std::string& target, int seconds) {
        // Load existing timeouts first
        auto timeouts = GetTimeouts();

        // Get current Unix timestamp
        auto now = std::chrono::system_clock::now();
        auto epoch = now.time_since_epoch();
        auto currentTime = std::chrono::duration_cast<std::chrono::seconds>(epoch).count();
        auto endTime = currentTime + seconds;

        TimeoutRecord timeout(target, endTime);

        // Add or update the timeout
        timeouts[target] = timeout;

        // Store as map<string, string> where value is JSON
        std::map<std::string, std::string> timeoutStrings;
        for (const auto& [key, val] : timeouts) {
            nlohmann::json tmp;
            tmp["user"] = val.user;
            tmp["until"] = val.until;
            timeoutStrings[key] = tmp.dump();
        }

        _state->Set(TIMEOUTS_KEY, timeoutStrings);
    }

    void Moderation::RemoveTimeout(const std::string& target) {
        // Load existing timeouts first
        auto timeouts = GetTimeouts();

        if (timeouts.find(target) != timeouts.end()) {
            timeouts.erase(target);

            // Convert back to string map
            std::map<std::string, std::string> timeoutStrings;
            for (const auto& [key, val] : timeouts) {
                nlohmann::json tmp;
                tmp["user"] = val.user;
                tmp["until"] = val.until;
                timeoutStrings[key] = tmp.dump();
            }

            _state->Set(TIMEOUTS_KEY, timeoutStrings);
        }
    }

    void Moderation::AddBlock(const std::string& target) {
        // Load existing blocks first
        auto blocks = GetBlockList();

        if (std::find(blocks.begin(), blocks.end(), target) == blocks.end()) {
            blocks.push_back(target);
            _state->Set(BLOCKS_KEY, blocks);
        }
    }

    void Moderation::RemoveBlock(const std::string& target) {
        // Load existing blocks first
        auto blocks = GetBlockList();

        auto it = std::find(blocks.begin(), blocks.end(), target);
        if (it != blocks.end()) {
            blocks.erase(it);
            _state->Set(BLOCKS_KEY, blocks);
        }
    }

    std::map<std::string, TimeoutRecord> Moderation::GetTimeouts() {
        std::map<std::string, TimeoutRecord> result;

        if (!_state->Has(TIMEOUTS_KEY)) {
            return result;  // Return empty map if key doesn't exist
        }

        try {
            // Get as map<string, string>
            auto timeoutStrings = _state->Get<std::map<std::string, std::string>>(TIMEOUTS_KEY);

            // Deserialize each JSON string
            for (const auto& [key, jsonStr] : timeoutStrings) {
                try {
                    auto j = nlohmann::json::parse(jsonStr);
                    TimeoutRecord record;
                    record.user = j["user"].get<std::string>();
                    record.until = j["until"].get<long long>();
                    result[key] = record;
                } catch (...) {
                    // Skip invalid entries
                }
            }
        } catch (...) {
            // Return empty map on error
        }

        return result;
    }

    std::vector<std::string> Moderation::GetBlockList() {
        if (!_state->Has(BLOCKS_KEY)) {
            return std::vector<std::string>();  // Return empty vector if key doesn't exist
        }

        try {
            return _state->Get<std::vector<std::string>>(BLOCKS_KEY);
        } catch (...) {
            return std::vector<std::string>();
        }
    }

    bool Moderation::IsBlocked(const std::string& target) {
        auto blocks = GetBlockList();
        return std::find(blocks.begin(), blocks.end(), target) != blocks.end();
    }

    bool Moderation::IsTimedOut(const std::string& target) {
        auto timeouts = GetTimeouts();

        if (timeouts.find(target) == timeouts.end()) {
            return false;
        }

        // Check if timeout has expired
        auto now = std::chrono::system_clock::now();
        auto epoch = now.time_since_epoch();
        auto currentTime = std::chrono::duration_cast<std::chrono::seconds>(epoch).count();

        auto& timeout = timeouts[target];
        if (currentTime >= timeout.until) {
            // Timeout expired, remove it
            const_cast<Moderation*>(this)->RemoveTimeout(target);
            return false;
        }

        return true;
    }
}