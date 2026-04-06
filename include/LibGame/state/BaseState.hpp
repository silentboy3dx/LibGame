#pragma once

#include <string>
#include <any>

namespace LibGame::State {
    class BaseState {
    public:
        virtual ~BaseState() = default;

        virtual void Set(const std::string &key, const std::any &value) = 0;

        virtual std::any Get(const std::string &key) = 0;

        template<typename T>
        T Get(const std::string &key) {
            return std::any_cast<T>(Get(key));
        }

        virtual bool Has(const std::string &key) = 0;

        virtual void Remove(const std::string &key) = 0;

        virtual std::string ToJson() = 0;
    };
}
