#include <cstring>
#include "Name.h"

void Name::copyName(const char *value, unsigned int size) {
    _size = size;
    _value = new char[_size + 1];
    strcpy(_value, value);
}

void Name::copyFrom(const Name &other) {
    copyName(other._value, other._size);
}

void Name::free() {
    delete[] _value;
    _value = nullptr;
    _size = 0;
}

Name::Name() {
    _value = new char[1];
    _value[0] = '\0';
    _size = 0;
}

Name::Name(const Name &other) {
    copyFrom(other);
}

Name &Name::operator=(const Name &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Name::~Name() {
    free();
}

const char *Name::getName() const {
    return _value;
}

void Name::setName(const char *value) {
    if (value == nullptr) {
        throw "Invalid name value!";
    }
    
    delete[] _value;
    copyName(value, strlen(value));
}
