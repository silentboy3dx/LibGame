#pragma once
#include "BaseModule.hpp"
#include "LibGame/misc/KvStore.hpp"

#include <unordered_map>
#include <vector>

namespace LibGame::Module {
    class Context final : public BaseModule, public Misc::KvStore {
    public:
        explicit Context(Interactions *core) : BaseModule(core) {
        }

        ~Context() override = default;

        Context &add(const std::string &key, const std::string &value) override;
        Context &remove(const std::string &key) override;
        Context &clear() override;

        Context &before(const std::string &line);
        Context &after(const std::string &line);

        template<typename TStatus>
        Context &SetPrimaryStatus(typename TStatus::Type status) {
            TStatus action(status);
            auto extra = action.getContext();
            for (auto &[k, v] : extra) {
                primaryContext[k] = v;
            }
            return *this;
        }

        template<typename TStatus>
        bool HasPrimaryStatus() const {
            return HasPrimaryStatus(TStatus::GetPrimaryActionName());
        }

        template<typename TStatus>
        Context& RemovePrimaryStatus() {
            primaryContext.clear();
            return *this;
        }

        Context& RemovePrimaryStatus() {
            primaryContext.clear();
            return *this;
        }

        template<typename TStatus>
        Context &AddSecondaryStatus(typename TStatus::Type status) {
            TStatus action(status);
            for (auto extra = action.getContext(); auto &[k, v] : extra) {
                secondaryContext[k] = v;
            }
            return *this;
        }

        template<typename TStatus>
        bool HasSecondaryStatus() const {
            return HasSecondaryStatus(TStatus::GetPrimaryActionName());
        }

        template<typename TStatus>
        Context& RemoveSecondaryStatus() {
            TStatus temp(TStatus::Type::Off);
            auto ctx = temp.getContext();
            for (const auto& [key, _] : ctx) {
                secondaryContext.erase(key);
            }
            return *this;
        }

        std::string toString() const;
        friend std::ostream &operator<<(std::ostream &os, const Context &ctx);

    private:
        std::vector<std::string> beforeLines;
        std::vector<std::string> afterLines;
        std::unordered_map<std::string, std::string> primaryContext;
        std::unordered_map<std::string, std::string> secondaryContext;

        bool HasPrimaryStatus(const std::string &name) const {
            return primaryContext.find(name) != primaryContext.end();
        }

        bool HasSecondaryStatus(const std::string &name) const {
            return secondaryContext.find(name) != secondaryContext.end();
        }
    };
}
