#include "IntWrapper.h"

IntWrapper::IntWrapper(int value) : value(value) {}

int IntWrapper::getValue() const {
    return value;
}

IntWrapper& IntWrapper::operator=(int newValue) {
    value = newValue;
    return *this;
}

IntWrapper& IntWrapper::operator++() {
    value += 1;
    return *this;
}

IntWrapper IntWrapper::operator++(int) {
    IntWrapper copy(*this);
    value++;
    return copy;
}

IntWrapper::operator bool() const {
    return value != 0;
}

// No need to make it friend we can use the getter
std::ostream &operator<<(std::ostream &out, const IntWrapper &integer) {
    return out << integer.getValue();
}

std::istream &operator>>(std::istream &in, IntWrapper &integer) {
    return in >> integer.value;
}