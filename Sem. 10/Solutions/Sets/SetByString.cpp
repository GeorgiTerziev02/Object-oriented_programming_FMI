#include "SetByString.h"
#include <cstring>
#include <utility>
#include <iostream>
#include <sstream>

void SetByString::fillSet() {
    reset();
    std::stringstream ss(str);

    while (!ss.eof()) {
        unsigned number;
        ss >> number;
        add(number);
    }
}

void SetByString::copyString(const char* str) {
    length = strlen(str);
    this->str = new char[length + 1];
    strcpy(this->str, str);
}

SetByString::SetByString(unsigned int max, const char* str)
    : Bitset(max)
{
    copyString(str ? str : "");
    fillSet();
}

SetByString::SetByString(const SetByString& other) : Bitset(other) {
    copyFrom(other);
}

SetByString::SetByString(SetByString&& other) noexcept : Bitset(std::move(other)) {
    moveFrom(std::move(other));
}

SetByString& SetByString::operator=(const SetByString& other) {
    if (this != &other) {
        Bitset::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

SetByString& SetByString::operator=(SetByString&& other) noexcept {
    if (this != &other) {
        Bitset::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

SetByString::~SetByString() {
    free();
}

bool SetByString::contains(unsigned n) const {
    return Bitset::contains(n);
}

void SetByString::print() const {
    Bitset::print();
}

void SetByString::setString(const char* str) {
    if (!str || this->str == str) {
        return;
    }

    delete[] this->str;
    copyString(str);
    fillSet();
}

void SetByString::setAt(size_t index, char ch) {
    if (index >= length) {
        throw std::exception("Invalid index");
    }

    str[index] = ch;
    fillSet();
}

void SetByString::copyFrom(const SetByString& other) {
    copyString(other.str);
}

void SetByString::free() {
    delete[] str;
    length = 0;
}

void SetByString::moveFrom(SetByString&& other) noexcept {
    str = other.str;
    length = other.length;

    other.str = nullptr;
    other.length = 0;
}
