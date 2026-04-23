#pragma once
#include <string>

namespace LibGame::Module {
    class Context;   // ← forward declaration
}

namespace LibGame::Statuses::Secondary {

    class SecondaryStatus {
    public:
        explicit SecondaryStatus(Module::Context& ctx)
            : ctx(ctx) {}

        virtual ~SecondaryStatus() = default;
        virtual void clear() = 0;

    protected:
        Module::Context& ctx;
    };

}
