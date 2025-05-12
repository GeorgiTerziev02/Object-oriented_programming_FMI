#include "MyString.h"
#include <cstring>
#pragma warning(disable:4996)

namespace StringHelperFunctions {
    unsigned int getNextPowerOfTwo(unsigned int n) {
        unsigned int step = 1;

        while ((n >> step) > 0) {
            n |= n >> step;
            step *= 2;
        }

        return n + 1;
    }
}

using namespace StringHelperFunctions;

void MyString::copyFrom(const MyString& other) {
    length = other.length;
    capacity = other.capacity;
    data = new char[capacity + 1];
    strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other) noexcept {
    data = other.data;
    length = other.length;
    capacity = other.capacity;

    other.data = nullptr;
    other.length = 0;
    other.capacity = 0;
}

void MyString::free() {
    delete[] data;
    data = nullptr;
    length = capacity = 0;
}

void MyString::resize(size_t lengthToFit) {
    capacity = length < 16 ? 15 : getNextPowerOfTwo(lengthToFit + 1) - 1;

    char* newData = new char[capacity + 1];
    strcpy(newData, data);
    delete[] data;

    data = newData;
}

MyString::MyString(size_t capacity) : capacity(capacity) {
    data = new char[capacity + 1];
}

MyString::MyString() : MyString("") { }

MyString::MyString(const char* str) {
    if (!str) {
        data = new char[capacity + 1];
        data[0] = '\0';
    }
    else {
        length = strlen(str);
        capacity = std::max((int)getNextPowerOfTwo(length), 16) - 1;
        data = new char[capacity + 1];
        strcpy(data, str);
    }
}

MyString::MyString(const MyString& other) {
    copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept {
    moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

MyString::~MyString() {
    free();
}

size_t MyString::getLength() const {
    return length;
}

size_t MyString::getCapacity() const {
    return capacity;
}

const char* MyString::c_str() const {
    return data;
}

MyString& MyString::operator+=(const MyString& other) {
    length += other.length;
    if (length >= capacity) {
        // resize with the new length
        resize(length);
    }

    //use strncat instead of strcat, because strcat will not work for str += str (the term zero of str will be destroyed by the first char)
    std::strncat(data, other.data, other.length);
    return *this;
}

MyString& MyString::operator+=(char ch) {
    if (length == capacity) {
        resize(length + 1);
    }
    data[length++] = ch;
    return *this;
}

char& MyString::operator[](size_t index) {
    return data[index];
}

char MyString::operator[](size_t index) const {
    return data[index];
}

MyString::operator bool() const {
    return length == 0;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    size_t resultLength = lhs.length + rhs.length;
    size_t capacity = getNextPowerOfTwo(resultLength) - 1;

    MyString res(capacity);
    strcpy(res.data, lhs.data);
    strcat(res.data, rhs.data);
    res.length = resultLength;

    return res;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buff[1024];
    is >> buff;

    delete[] str.data;
    str.length = strlen(buff);
    str.capacity = std::max((int)getNextPowerOfTwo(str.length), 16) - 1;
    str.data = new char[str.capacity + 1];
    strcpy(str.data, buff);

    return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    return os << str.c_str();
}

bool operator<(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}