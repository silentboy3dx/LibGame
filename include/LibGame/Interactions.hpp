#pragma once

#include <functional>

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
    class BaseInteraction;
    using NotificationCallback = std::function<void(const std::string &)>;


    class Interactions {
    public:
        Interactions();

        ~Interactions();

        void OnVerbose(NotificationCallback cb) { verbose_callback = std::move(cb); };
        void OnDebug(NotificationCallback cb) { debug_callback = std::move(cb); };
        void OnWarn(NotificationCallback cb) { warn_callback = std::move(cb); };
        void OnError(NotificationCallback cb) { error_callback = std::move(cb); };
        void OnCritical(NotificationCallback cb) { critical_callback = std::move(cb); };

        void Verbose(const std::string &message) const {
            if (verbose_callback) {
                verbose_callback(message);
            }
        }

        void Debug(const std::string &message) const {
            if (debug_callback) {
                debug_callback(message);
            }
        }

        void Warn(const std::string &message) const {
            if (warn_callback) {
                warn_callback(message);
            }
        }

        void Error(const std::string &message) const {
            if (error_callback) {
                error_callback(message);
            }
        }

        void Critical(const std::string &message) const {
            if (critical_callback) {
                critical_callback(message);
            }
        }

        static Interactions &GetInstance();

        static bool IsGameInForeground();

        void SetState(std::unique_ptr<BaseState> state) {
            _state = std::move(state);
        }

        BaseState *GetState() {
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
        std::unordered_map<std::string, std::shared_ptr<BaseInteraction> > _interactions;
        std::unordered_map<std::type_index, std::string> _typeMap;

        NotificationCallback verbose_callback;
        NotificationCallback debug_callback;
        NotificationCallback warn_callback;
        NotificationCallback error_callback;
        NotificationCallback critical_callback;
    };

    class BaseInteraction {
    public:
        explicit BaseInteraction(Interactions *base) : core(base) {
        }

        virtual ~BaseInteraction() = default;

        void Verbose(const std::string &message) const {
            if (core) {
                core->Verbose(message);
            }
        }

        void Debug(const std::string &message) const {
            if (core) {
                core->Debug(message);
            }
        }

        void Warn(const std::string &message) const {
            if (core) {
                core->Warn(message);
            }
        }

        void Error(const std::string &message) const {
            if (core) {
                core->Error(message);
            }
        }

        void Critical(const std::string &message) const {
            if (core) {
                core->Critical(message);
            }
        }

    protected:
        Interactions *core = nullptr;
    };
}
