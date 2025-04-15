#include "MyString.h"
#include <cstring>
#pragma warning(disable:4996)

// StringHelperFunctions
namespace {
    unsigned int getNextPowerOfTwo(unsigned int n) {
        unsigned int step = 1;

        while ((n >> step) > 0) {
            n |= n >> step;
            step *= 2;
        }

        return n + 1;
    }

    namespace ErrorMessages {
        const char* INVALID_INDEX = "Invalid index";
        const char* NULL_STRING = "String is nullptr";
    }
}

// namespace ErrorMessages {
//     const char* const INVALID_INDEX = "Invalid index";
// }

void MyString::validateIndex(size_t index) const {
    if (index >= length) {
        throw std::out_of_range(ErrorMessages::INVALID_INDEX);
    }
}

void MyString::copyDynamic(const MyString& other) {
    data = new char[other.capacity + 1];
    strcpy(data, other.data);
}

void MyString::freeDynamic() {
    delete[] data;
}

void MyString::resize(size_t lengthToFit) {
    capacity = getNextPowerOfTwo(lengthToFit) - 1;

    char* newData = new char[capacity + 1];
    strcpy(newData, data);
    delete[] data;
    data = newData;
}

MyString::MyString(size_t capacity) : capacity(capacity), length(0) {
    data = new char[capacity + 1];
}

MyString::MyString() : MyString("") { }

MyString::MyString(const char* str) {
    if (!str) {
        throw std::invalid_argument(ErrorMessages::NULL_STRING);
    }

    length = strlen(str);
    capacity = getNextPowerOfTwo(length) - 1;
    this->data = new char[capacity + 1];
    strcpy(this->data, str);
}

MyString::MyString(const MyString& other) : length(other.length), capacity(other.capacity) {
    copyDynamic(other);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        freeDynamic();
        length = other.length;
        capacity = other.capacity;
        copyDynamic(other);
    }

    return *this;
}

MyString::~MyString() {
    freeDynamic();
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

char& MyString::at(size_t index) {
    validateIndex(index);
    return data[index];
}

char MyString::at(size_t index) const {
    validateIndex(index);
    return data[index];
}

char& MyString::operator[](size_t index) {
    validateIndex(index);
    return data[index];
}

char MyString::operator[](size_t index) const {
    validateIndex(index);
    return data[index];
}

MyString& MyString::operator+=(const MyString& other) {
    if (capacity <= length + other.length) {
        resize(length + other.length);
    }

    //use strncat instead of strcat, because strcat will not work for str += str
    // the term zero will be destroyed while copying the rightside, but the end of the
    // right side is that exact zero => strcat won't know when to stop
    strncat(data, other.data, other.length);
    // this should be updated last because of str += str
    length = length + other.length;

    return *this;
}

MyString& MyString::operator+=(char ch) {
    if (length == capacity) {
        resize(length + 1);
    }
    data[length++] = ch;
    return *this;
}

MyString::operator bool() const {
    return length != 0;
}

// Not optimal because we allocate memory twice
// 1. copy constructor
// 2. += deletes the allocated from the copy constructor and allocates new memory
// MyString operator+(const MyString& lhs, const MyString& rhs) {
// 	MyString result(lhs);
// 	result += rhs;
// 	return result;
// }

// more optimal => creating a new string with the needed capacity
// using the private capacity constructor
MyString operator+(const MyString& lhs, const MyString& rhs) {
    size_t resultLength = lhs.length + rhs.length;
    size_t capacity = getNextPowerOfTwo(resultLength) - 1;

    MyString result(capacity);
    strcpy(result.data, lhs.data);
    strcat(result.data, rhs.data);
    result.length = resultLength;

    return result;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buff[1024];
    is >> buff;

    // the string might had previously allocated data
    delete[] str.data;
    str.length = strlen(buff);
    str.capacity = getNextPowerOfTwo(str.length) - 1;
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
