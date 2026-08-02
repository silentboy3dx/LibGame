#pragma once
#include "LibGame/Interactions.hpp"

#include <LibIO/ClipboardControls.hpp>

#include <chrono>
#include <string>

using namespace LibIO::Clipboard;

namespace LibGame::Io {
    class Clipboard final : public BaseInteraction {
    public:
        /**
         * Alias zodat aanroepers niet rechtstreeks tegen LibIO hoeven te praten:
         *
         *     Clipboard::Transaction tx;
         */
        using Transaction = LibIO::Clipboard::ClipboardControls::Transaction;

        explicit Clipboard(Interactions *core);
        ~Clipboard() override = default;

        void Copy(std::string text) ;
        std::string Paste();
        void Clear() ;

        bool CopyAndConfirm(const std::string &text,
                            std::chrono::milliseconds timeout = std::chrono::milliseconds(750));

        std::string WaitForChange(const std::string &previous,
                                  std::chrono::milliseconds timeout = std::chrono::milliseconds(500));

    private:
        ClipboardControls *Controller = nullptr;
    };
}
