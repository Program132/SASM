#pragma once

#include <iostream>
#include <string_view>

namespace SASM::Parser {
    class Memory {
    private:
        std::string value;
        int slot{};

    public:
        Memory();
        Memory(std::string_view value, int slot);

        std::string getValue();
        [[nodiscard]] int getSlot() const;
        void setValue(std::string_view v);
        void setSlot(int v);
    };
}