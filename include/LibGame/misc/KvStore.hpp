#pragma once

#include <unordered_map>
#include <string>

namespace LibGame::Misc {
    class KvStore {
    public:
        virtual ~KvStore() = default;

        virtual KvStore &add(const std::string &key, const std::string &value) {
            store[key] = value;
            return *this;
        }

        virtual std::string get(const std::string &key) const {
            return store.at(key);
        }

        virtual KvStore &remove(const std::string &key) {
            store.erase(key);
            return *this;
        }

        virtual KvStore &clear() {
            store.clear();
            return *this;
        }

        virtual std::unordered_map<std::string, std::string> getContext() const {
            return store;
        }

    protected:
        std::unordered_map<std::string, std::string> store;
    };
}
