#include "LibGame/module/Context.hpp"

namespace LibGame::Module {
    Context &Context::add(const std::string &key, const std::string &value) {
        context[key] = value;
        return *this;
    }

    Context &Context::remove(const std::string &key) {
        context.erase(key);
        return *this;
    }

    Context &Context::clear() {
        context.clear();
        beforeLines.clear();
        afterLines.clear();
        return *this;
    }

    Context &Context::before(const std::string &line) {
        beforeLines.push_back(line);
        return *this;
    }

    Context &Context::after(const std::string &line) {
        afterLines.push_back(line);
        return *this;
    }

    std::string Context::toString() const {
        std::ostringstream oss;

        for (const auto &line: beforeLines) {
            oss << line << "\n";
        }

        for (const auto &kv: context) {
            oss << kv.first << ": " << kv.second << "\n";
        }

        for (const auto &line: afterLines) {
            oss << line << "\n";
        }

        return oss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Context& ctx) {
        os << ctx.toString();
        return os;
    }
}
