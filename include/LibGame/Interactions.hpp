#pragma once

#include "LibGame/state/BaseState.hpp"

#include <unordered_map>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>

#include <typeindex>
#include <typeinfo>

using namespace LibGame::State;

namespace LibGame {

    class Interactions;

    class BaseInteraction {
    public:
        explicit BaseInteraction(Interactions* base) : core(base) {}
        virtual ~BaseInteraction() = default;

    protected:
        Interactions* core;
    };


    class Interactions {
    public:
        Interactions();
        ~Interactions();

        // Destructor mag default blijven
        // ~Interactions() = default;

        static Interactions& GetInstance();
        static bool IsGameInForeground();

        void SetState(std::unique_ptr<BaseState> state) {
            _state = std::move(state);
        }

        BaseState* GetState() {
            return _state.get();
        }

        template<typename T>
        void RegisterInteraction() {
            std::string name = typeid(T).name();
            size_t pos = name.find_last_of(':');
            if (pos != std::string::npos) {
                name = name.substr(pos + 1);
            }

            auto instance = std::make_shared<T>(this);
            _interactions[name] = instance;
            _typeMap[std::type_index(typeid(T))] = name;
        }

        template<typename T>
        void RegisterModule() { return RegisterInteraction<T>(); }

        template<typename T>
        T& GetInteraction() {
            auto typeIdx = std::type_index(typeid(T));
            auto it = _typeMap.find(typeIdx);

            if (it != _typeMap.end()) {
                auto& name = it->second;
                auto interactionIt = _interactions.find(name);

                if (interactionIt != _interactions.end()) {
                    auto ptr = std::dynamic_pointer_cast<T>(interactionIt->second);
                    if (ptr) {
                        return *ptr;
                    }
                }
            }

            std::string name = typeid(T).name();
            size_t pos = name.find_last_of(':');
            if (pos != std::string::npos) {
                name = name.substr(pos + 1);
            }

            std::ostringstream oss;
            oss << "Interaction " << name << " not found";
            throw std::runtime_error(oss.str());
        }

    private:
        std::unique_ptr<BaseState> _state;
        std::unordered_map<std::string, std::shared_ptr<BaseInteraction>> _interactions;
        std::unordered_map<std::type_index, std::string> _typeMap;
    };
}
