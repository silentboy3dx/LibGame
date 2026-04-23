#pragma once
#include "BaseModule.hpp"
#include "LibGame/misc/KvStore.hpp"
#include "LibGame/statuses/secondary/SecondaryStatus.hpp"
#include "LibGame/statuses/primary//PrimaryStatus.hpp"

#include <unordered_map>
#include <vector>
#include <string>
#include <type_traits>
#include <typeindex>
#include <memory>
#include <algorithm>

namespace LibGame::Module {

    class Context final : public BaseModule, public Misc::KvStore {
    public:
        explicit Context(Interactions* core) noexcept : BaseModule(core) {}
        ~Context() override = default;

        Context& add(const std::string& key, const std::string& value) override;
        Context& remove(const std::string& key) override;
        Context& clear() override;

        Context& before(const std::string& line);
        Context& after(const std::string& line);

        template <typename TStatus>
        TStatus& SetPrimaryStatus(TStatus::Type status) {
            static_assert(std::is_base_of_v<Statuses::Primary::PrimaryStatus, TStatus>);

            using Base = Statuses::Primary::PrimaryStatus;
            using BasePtr = std::unique_ptr<Base>;

            auto raw = new TStatus(*this, status);
            TStatus& ref = *raw;

            primaryInstances[typeid(TStatus)] = BasePtr(raw);
            return ref;
        }

        template<typename TStatus>
        TStatus* GetPrimaryStatus() {
            auto it = primaryInstances.find(typeid(TStatus));
            if (it == primaryInstances.end()) return nullptr;
            return static_cast<TStatus*>(it->second.get());
        }

        template<typename TStatus>
        Context& RemovePrimaryStatus() {

            auto it = primaryInstances.find(typeid(TStatus));
            if (it == primaryInstances.end())
                return *this;

            primaryInstances[typeid(TStatus)]->clear();
            primaryInstances.erase(it);
            primaryInstances.clear();

            return *this;
        }

        template<typename TStatus>
        bool HasPrimaryStatus() const {
            auto it = primaryInstances.find(typeid(TStatus));
            return (it != primaryInstances.end());
        }

        template <typename TStatus>
        TStatus& AddSecondaryStatus(TStatus::Type status) {
            static_assert(std::is_base_of_v<Statuses::Secondary::SecondaryStatus, TStatus>);
            auto instance = std::make_unique<TStatus>(*this, status);

            TStatus& ref = *instance;
            secondaryInstances[typeid(TStatus)] = std::move(instance);
            return ref;
        }

        template<typename TStatus>
        TStatus* GetSecondaryStatus() {
            auto it = secondaryInstances.find(typeid(TStatus));
            if (it == secondaryInstances.end()) return nullptr;
            return static_cast<TStatus*>(it->second.get());
        }

        template<typename TStatus>
        Context& RemoveSecondaryStatus() {
            static_assert(std::is_base_of_v<Statuses::Secondary::SecondaryStatus, TStatus>);

            auto it = secondaryInstances.find(typeid(TStatus));
            if (it == secondaryInstances.end())
                return *this;

            remove(TStatus::GetPrimaryActionName());
            secondaryInstances[typeid(TStatus)]->clear();
            secondaryInstances.erase(it);
            return *this;
        }

        template<typename TStatus>
        bool HasSecondaryStatus() const {
            static_assert(std::is_base_of_v<Statuses::Secondary::SecondaryStatus, TStatus>);

            auto it = secondaryInstances.find(typeid(TStatus));
            return  (it != secondaryInstances.end());

        }

        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Context& ctx);

    private:
        std::vector<std::string> beforeLines;
        std::vector<std::string> afterLines;

        std::unordered_map<std::type_index, std::unique_ptr<Statuses::Primary::PrimaryStatus>> primaryInstances;
        std::unordered_map<std::type_index, std::unique_ptr<Statuses::Secondary::SecondaryStatus>> secondaryInstances;
    };

}
