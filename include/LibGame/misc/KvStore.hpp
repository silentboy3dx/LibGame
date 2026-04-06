#pragma once

#include <unordered_map>
#include <string>

namespace LibGame::Misc {
    class KvStore {
    public:
        virtual ~KvStore() = default;

        // Voeg een key/value toe
        virtual KvStore &add(const std::string &key, const std::string &value) {
            store[key] = value;
            return *this;
        }

        // Verwijder een key
        virtual KvStore &remove(const std::string &key) {
            store.erase(key);
            return *this;
        }

        // Maak de store leeg
        virtual KvStore &clear() {
            store.clear();
            return *this;
        }

        // Haal de volledige context op
        virtual std::unordered_map<std::string, std::string> getContext() const {
            return store;
        }

    protected:
        std::unordered_map<std::string, std::string> store;
    };
}
