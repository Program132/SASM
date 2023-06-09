#include "Memory.h"

using namespace SASM::Parser;

std::string Memory::getValue() {
    return this->value;
}

int Memory::getSlot() const {
    return this->slot;
}

void Memory::setValue(std::string_view v) {
    this->value = v;
}

void Memory::setSlot(int v) {
   this->slot = v;
}

Memory::Memory(std::string_view value, int slot) {
    this->setSlot(slot);
    this->setValue(value);
}

Memory::Memory() = default;
