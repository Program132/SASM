#pragma once

#include <iostream>

namespace SASM::Definitions {
    class Register {
    private:
        std::string name;
        std::string value;
        int memorySlot{};

    public:
        Register();
        Register(std::string name, std::string value);

        std::string getName();
        void setName(std::string& name);
        [[nodiscard]] int getMemorySlot() const;
        void setMemorySlot(int& slot);
        std::string getValue();
        void setValue(const std::string& value);
    };
}