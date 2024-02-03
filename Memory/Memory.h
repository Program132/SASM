#pragma once

#include <iostream>

namespace SASM::Definitions {
    class Memory {
    private:
        std::string value;
        int slot{};

    public:
        Memory();
        Memory(std::string_view value, int slot);

        std::string getValue();
        void setValue(std::string const& value);
        int getSlot() const;
        void setSlot(int const& slot);
    };
}