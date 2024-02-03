#include "Memory.h"

namespace SASM::Definitions {
    Memory::Memory() = default;


    Memory::Memory(std::string_view value, int slot) {
        this->value = value;
        this->slot = slot;
    }

    std::string Memory::getValue() {
        return this->value;
    }

    void Memory::setValue(std::string const& value) {
        this->value = value;
    }

    int Memory::getSlot() const {
        return this->slot;
    }

    void Memory::setSlot(int const& slot) {
        this->slot = slot;
    }
}