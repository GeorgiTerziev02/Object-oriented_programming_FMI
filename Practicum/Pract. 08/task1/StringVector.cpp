#include "StringVector.h"

void StringVector::resize() {
    capacity = (capacity + 1) * 2;
    String* newData = new String[capacity];
    for (unsigned i = 0; i < size_; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

void StringVector::copyFrom(const StringVector& other) {
    size_ = other.size_;
    capacity = other.capacity;
    data = new String[capacity];
    for (unsigned i = 0; i < size_; i++)
        data[i] = other.data[i];
}


void StringVector::free() {
    delete[] data;
    data = nullptr;
    size_ = 0;
    capacity = 0;
}

StringVector::StringVector() {
    size_ = 0;
    capacity = 8;
    data = new String[capacity];
}

StringVector::StringVector(const StringVector& other) {
    copyFrom(other);
}

StringVector& StringVector::operator=(const StringVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

StringVector::~StringVector() {
    free();
}

void StringVector::push_back(const String& str) {
    if (size_ == capacity)
        resize();
    data[size_++] = str;
}

void StringVector::pop_back() {
    if (size_ == 0)
        throw "pop_back on empty vector";
    size_--;
}

void StringVector::insert(unsigned index, const String& str) {
    if (index > size_)
        throw "insert index out of range";
    if (size_ == capacity)
        resize();
    for (unsigned i = size_; i > index; i--)
        data[i] = data[i - 1];
    data[index] = str;
    size_++;
}

void StringVector::erase(unsigned index) {
    if (index >= size_)
        throw "erase index out of range";
    for (unsigned i = index; i < size_ - 1; i++)
        data[i] = data[i + 1];
    size_--;
}

void StringVector::clear() {
    size_ = 0;
}

String& StringVector::at(unsigned index) {
    if (index >= size_)
        throw "at index out of range";
    return data[index];
}

const String& StringVector::at(unsigned index) const {
    if (index >= size_)
        throw "at index out of range";
    return data[index];
}

bool StringVector::empty() const {
    return size_ == 0;
}

unsigned StringVector::size() const {
    return size_;
}
