#pragma once

#include "BaseModule.hpp"

namespace LibGame::Module {
    class Strapon final : public BaseModule {
    public:
        explicit Strapon(Interactions *core) : BaseModule(core) {};
        ~Strapon() override = default;

        bool Off() const;
        bool Penis() const;
        bool Toy1() const;
        bool Toy2() const;
    };
}
