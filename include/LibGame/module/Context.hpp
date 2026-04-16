#pragma once
#include "BaseModule.hpp"
#include "LibGame/misc/KvStore.hpp"

#include <unordered_map>
#include <vector>
#include <string>
#include <type_traits>
#include <ostream>
#include <algorithm>

namespace LibGame::Module {

    class Context final : public BaseModule, public Misc::KvStore {
    public:
        explicit Context(Interactions* core) noexcept : BaseModule(core) {}
        ~Context() override = default;

        // KvStore overrides (global context)
        Context& add(const std::string& key, const std::string& value) override;
        Context& remove(const std::string& key) override;
        Context& clear() override;

        // Extra tekst voor/na context
        Context& before(const std::string& line);
        Context& after(const std::string& line);

        // PRIMARY ACTION (single-primary)
        template <typename TStatus>
        Context& SetPrimaryAction(typename TStatus::Type status) {
            static_assert(std::is_base_of_v<Misc::KvStore, TStatus>,
                          "TStatus must inherit from KvStore");

            TStatus action(status);
            primaryContext = action.getContext();
            return *this;
        }

        template<typename TStatus>
        Context& RemovePrimaryStatus() {
            primaryContext.clear();
            return *this;
        }

        Context& RemovePrimaryAction();

        template<typename TStatus>
        bool HasPrimaryStatus() const {
            static_assert(std::is_base_of_v<Misc::KvStore, TStatus>,
                          "TStatus must inherit from KvStore");

            TStatus tmp(static_cast<typename TStatus::Type>(0));
            auto keys = tmp.getContext();

            return std::ranges::all_of(keys, [&](const auto& kv) {
                return primaryContext.contains(kv.first);
            });
        }

        // SECONDARY ACTION (multi-secondary)
        template <typename TStatus>
        Context& AddSecondaryAction(typename TStatus::Type status) {
            static_assert(std::is_base_of_v<Misc::KvStore, TStatus>,
                          "TStatus must inherit from KvStore");

            TStatus action(status);
            auto ctx = action.getContext();

            for (const auto& [k, v] : ctx) {
                secondaryContext[k] = v;
            }
            return *this;
        }

        template<typename TStatus>
        Context& RemoveSecondaryStatus() {
            static_assert(std::is_base_of_v<Misc::KvStore, TStatus>,
                          "TStatus must inherit from KvStore");

            TStatus tmp(static_cast<typename TStatus::Type>(0));
            auto ctx = tmp.getContext();

            for (const auto& [k, _] : ctx) {
                secondaryContext.erase(k);
            }
            return *this;
        }

        Context& RemoveSecondaryAction();

        template<typename TStatus>
        bool HasSecondaryStatus() const {
            static_assert(std::is_base_of_v<Misc::KvStore, TStatus>,
                          "TStatus must inherit from KvStore");

            TStatus tmp(static_cast<typename TStatus::Type>(0));
            auto ctx = tmp.getContext();

            return std::ranges::all_of(ctx, [&](const auto& kv) {
                return secondaryContext.contains(kv.first);
            });
        }

        // Debug
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Context& ctx);

    private:
        std::vector<std::string> beforeLines;
        std::vector<std::string> afterLines;

        std::unordered_map<std::string, std::string> primaryContext;
        std::unordered_map<std::string, std::string> secondaryContext;
    };

}
