#include "StringVector.h"

#include <iostream>
#include <stdexcept>

void StringVector::copyFrom(const StringVector& other) {
    vector = new String[other.capacity];
    for (size_t i = 0; i < size; ++i) {
        vector[i] = other[i];
    }
}
void StringVector::copyFrom(const String* arr, size_t size) {
    vector = new String[size*2];
    for (size_t i = 0; i < size; ++i) {
        vector[i] = arr[i];
    }
}
void StringVector::checkAndResize(){
    if(size == capacity){
        resize();
    }
}

StringVector::StringVector() : size(0), capacity(DEFAULT_CAPACITY) {
    vector = new String[DEFAULT_CAPACITY];
}
StringVector::StringVector(const String* arr, size_t size): size(size), capacity(size*2) {
    copyFrom(arr, size);
}
StringVector::StringVector(const StringVector& other): size(other.size), capacity(other.capacity) {
    copyFrom(other);
}
StringVector& StringVector::operator=(const StringVector& other) {
    if (this != &other) {
        String* newVector = new String[other.capacity];
        for (size_t i = 0; i < other.size; ++i) {
            newVector[i] = other.vector[i];
        }
        delete[] vector;
        vector = newVector;
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}
StringVector::~StringVector() {
    clear();
}
void StringVector::resize() {
    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        String* newVector = new String[capacity];
        for (size_t i = 0; i < size; ++i) {
            newVector[i] = vector[i];
        }
        delete[] vector;
        vector = newVector;
    }
}
void StringVector::push_back(const std::string& str) {
    checkAndResize();
    vector[size++] = str;
}
void StringVector::pop_back() {
    if(size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    vector[--size] = String();
}
void StringVector::insert(size_t index, const std::string& str) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }
    checkAndResize();
    for (size_t i = size; i > index; --i) {
        vector[i] = vector[i - 1];
    }
    vector[index] = str;
    ++size;
}
void StringVector::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        vector[i] = vector[i + 1];
    }
    --size;
}
void StringVector::clear() {
    delete[] vector;
    vector = nullptr;
    size = capacity = 0;
}
std::String& StringVector::operator[](size_t index) {
    /*if (index >= size) {  conv
        throw std::out_of_range("Index out of range");
    }*/
    return vector[index];
}
const std::String& StringVector::operator[](size_t index) const {
    /*if (index >= size) { conv
        throw std::out_of_range("Index out of range");
    }*/
    return vector[index];
}
String& StringVector::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return vector[index];
}
const String& StringVector::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return vector[index];
}
bool StringVector::empty() const {
    return size == 0;
}
size_t StringVector::size() const {
    return size;
}