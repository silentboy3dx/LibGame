#pragma once

#include <stdexcept>
#include <string>
#include <utility>

namespace LibGame::Exceptions {
    class AssetException : public std::runtime_error {
    public:
        explicit AssetException(std::string msg, std::string module)
            : std::runtime_error(msg), mod(std::move(module)) {}

        const char* module() const noexcept {
            return mod.c_str();
        }

    private:
        std::string mod;
    };
}