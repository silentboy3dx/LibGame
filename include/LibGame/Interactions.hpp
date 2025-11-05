#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>

#include <typeindex>
#include <typeinfo>

// #include "asset/Assets.hpp"
// #include "detect/Detector.hpp"

// using namespace LibGame::Detect;
// using namespace LibGame::Asset;

namespace LibGame {
    class Interactions;

    class BaseInteraction {
    public:
        explicit BaseInteraction(Interactions *base) { core = base; }

        virtual ~BaseInteraction() = default;

    protected:
        Interactions *core;
    };


    class Interactions {
    public:
        Interactions();

        ~Interactions() = default;

        static Interactions &GetInstance();

        template<typename T>
                void RegisterInteraction() {
            // Get the type name automatically
            std::string name = typeid(T).name();
            // Remove any namespace prefixes if needed
            size_t pos = name.find_last_of(':');
            if (pos != std::string::npos) {
                name = name.substr(pos + 1);
            }

            auto instance = std::make_shared<T>(this);
            _interactions[name] = instance;
            _typeMap[std::type_index(typeid(T))] = name;
        }

        template<typename T>
                void RegisterModule() { return RegisterInteraction<T>();}

        template<typename T>
        T &GetInteraction() {
            auto typeIdx = std::type_index(typeid(T));
            auto it = _typeMap.find(typeIdx);

            if (it != _typeMap.end()) {
                auto &name = it->second;
                auto interactionIt = _interactions.find(name);

                if (interactionIt != _interactions.end()) {
                    auto ptr = std::dynamic_pointer_cast<T>(interactionIt->second);
                    if (ptr) {
                        return *ptr;
                    }
                }
            }

            std::string name = typeid(T).name();
            // Remove any namespace prefixes if needed
            size_t pos = name.find_last_of(':');
            if (pos != std::string::npos) {
                name = name.substr(pos + 1);
            }

            std::ostringstream oss;
            oss << "Interaction " << name << " not found";
            throw std::runtime_error(oss.str());
        }


        static bool IsGameInForeground();

    private:
        std::unordered_map<std::string, std::shared_ptr<BaseInteraction> > _interactions;
        std::unordered_map<std::type_index, std::string> _typeMap;
        static Interactions *_instance;
    };
}
