#pragma once

#include "BaseModule.hpp"
#include <string>
#include <vector>
#include <map>

namespace LibGame::Module {
    struct TimeoutRecord {
        std::string user;
        long long until;  // Unix timestamp

        TimeoutRecord() : user(""), until(0) {}
        TimeoutRecord(const std::string& u, long long t) : user(u), until(t) {}
    };

    class Moderation final : public BaseModule {
    public:
        explicit Moderation(Interactions *core);
        ~Moderation() override = default;

        void AddTimeout(const std::string& target, int seconds) const;
        void RemoveTimeout(const std::string& target) const;

        void AddBlock(const std::string& target) const;
        void RemoveBlock(const std::string& target) const;

        std::map<std::string, TimeoutRecord> GetTimeouts() const;
        std::vector<std::string> GetBlockList() const;

        bool IsBlocked(const std::string& target) const;
        bool IsTimedOut(const std::string& target) const;

    private:
        static constexpr const char* TIMEOUTS_KEY = "game_moderation_timeouts";
        static constexpr const char* BLOCKS_KEY = "game_moderation_blocks";

        BaseState* _state = nullptr;
    };
}