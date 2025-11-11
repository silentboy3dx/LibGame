#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Context final : public BaseModule {
    public:
        explicit Context(Interactions *core) : BaseModule(core) {
        };

        ~Context() override = default;

        Context& add(const std::string& key, const std::string& value);
        Context& remove(const std::string& key);
        Context& clear();
        Context& before(const std::string& line);
        Context& after(const std::string& line);
        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& os, const Context& ctx);

    private:
        std::unordered_map<std::string, std::string> context;
        std::vector<std::string> beforeLines;
        std::vector<std::string> afterLines;
    };
}
