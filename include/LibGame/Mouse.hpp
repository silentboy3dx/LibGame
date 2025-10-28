#include <iostream>

#include "InteractionBase.hpp"

namespace LibGame {
    class Interactions;

    class Mouse : public InteractionBase {
    private:
        Interactions *_owner;

    public:
        Mouse(Interactions *owner) : _owner(owner) {
        }

        void Click() {
            std::cout << "Mouse clicked" << std::endl;
        }
    };
}

