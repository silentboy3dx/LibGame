#pragma once

namespace LibGame::Module {
    class Context;   // ← forward declaration
}

namespace LibGame::Statuses::Primary{

    class PrimaryStatus {
    public:
        explicit PrimaryStatus(Module::Context& ctx)
            : ctx(ctx) {}

        virtual ~PrimaryStatus() = default;
        virtual void clear() = 0;

    protected:
        Module::Context& ctx;
    };

}
