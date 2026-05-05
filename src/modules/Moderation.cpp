#include "LibGame/module/Moderation.hpp"

#include <nlohmann/json.hpp>

#include <chrono>

namespace LibGame::Module {

    Moderation::Moderation(Interactions *core) : BaseModule(core) {
        _state = core->GetState();

        // DON'T initialize empty collections - let GetTimeouts/GetBlockList handle that
        // This way existing data from file is preserved
    }

    void Moderation::AddTimeout(const std::string& target, int seconds) const {
        auto timeouts = GetTimeouts();

        const auto now = std::chrono::system_clock::now();
        const auto epoch = now.time_since_epoch();
        const auto currentTime = std::chrono::duration_cast<std::chrono::seconds>(epoch).count();
        const auto endTime = currentTime + seconds;

        const TimeoutRecord timeout(target, endTime);

        timeouts[target] = timeout;

        std::map<std::string, std::string> timeoutStrings;
        for (const auto& [key, val] : timeouts) {
            nlohmann::json tmp;
            tmp["user"] = val.user;
            tmp["until"] = val.until;
            timeoutStrings[key] = tmp.dump();
        }

        _state->Set(TIMEOUTS_KEY, timeoutStrings);
    }

    void Moderation::RemoveTimeout(const std::string& target) const {
        auto timeouts = GetTimeouts();

        if (timeouts.contains(target)) {
            timeouts.erase(target);

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

    void Moderation::AddBlock(const std::string& target) const {
        if (auto blocks = GetBlockList(); std::ranges::find(blocks, target) == blocks.end()) {
            blocks.push_back(target);
            _state->Set(BLOCKS_KEY, blocks);
        }
    }

    void Moderation::RemoveBlock(const std::string& target) const {
        auto blocks = GetBlockList();

        if (const auto it = std::ranges::find(blocks, target); it != blocks.end()) {
            blocks.erase(it);
            _state->Set(BLOCKS_KEY, blocks);
        }
    }

    std::map<std::string, TimeoutRecord> Moderation::GetTimeouts() const {
        std::map<std::string, TimeoutRecord> result;

        if (!_state->Has(TIMEOUTS_KEY)) {
            return result;
        }

        try {
            auto timeoutStrings = _state->Get<std::map<std::string, std::string>>(TIMEOUTS_KEY);

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

    std::vector<std::string> Moderation::GetBlockList() const {
        if (!_state->Has(BLOCKS_KEY)) {
            return {};
        }

        try {
            return _state->Get<std::vector<std::string>>(BLOCKS_KEY);
        } catch (...) {
            return {};
        }
    }

    bool Moderation::IsBlocked(const std::string& target) const {
        auto blocks = GetBlockList();
        return std::ranges::find(blocks, target) != blocks.end();
    }

    bool Moderation::IsTimedOut(const std::string& target) const {
        auto timeouts = GetTimeouts();

        if (!timeouts.contains(target)) {
            return false;
        }

        const auto now = std::chrono::system_clock::now();
        const auto epoch = now.time_since_epoch();
        const auto currentTime = std::chrono::duration_cast<std::chrono::seconds>(epoch).count();

        if (auto& timeout = timeouts[target]; currentTime >= timeout.until) {
            this->RemoveTimeout(target);
            return false;
        }

        return true;
    }
}