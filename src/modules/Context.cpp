#include "LibGame/module/Context.hpp"

namespace LibGame::Module {

    Context& Context::add(const std::string& key, const std::string& value) {
        KvStore::add(key, value);
        return *this;
    }

    Context& Context::remove(const std::string& key) {
        KvStore::remove(key);
        return *this;
    }

    Context& Context::clear() {
        KvStore::clear();
        primaryContext.clear();
        secondaryContext.clear();
        beforeLines.clear();
        afterLines.clear();
        return *this;
    }

    Context& Context::before(const std::string& line) {
        beforeLines.push_back(line);
        return *this;
    }

    Context& Context::after(const std::string& line) {
        afterLines.push_back(line);
        return *this;
    }

    // Nieuw: verwijderen van acties
    Context& Context::RemovePrimaryAction() {
        primaryContext.clear();
        return *this;
    }

    Context& Context::RemoveSecondaryAction() {
        secondaryContext.clear();
        return *this;
    }

    std::string Context::toString() const {
        std::ostringstream oss;

        for (const auto& line : beforeLines) {
            oss << line << "\n";
        }

        for (const auto& [k,v] : primaryContext) {
            oss << k << ": " << v << "\n";
        }

        for (const auto& [k,v] : secondaryContext) {
            oss << k << ": " << v << "\n";
        }

        for (const auto& [k,v] : KvStore::getContext()) {
            oss << k << ": " << v << "\n";
        }

        for (const auto& line : afterLines) {
            oss << line << "\n";
        }

        return oss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Context& ctx) {
        os << ctx.toString();
        return os;
    }
}
