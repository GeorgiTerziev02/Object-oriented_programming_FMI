#pragma once

#include <iostream>
#include "String.h"

#define DEFAULT_CAPACITY 8

class StringVector {
private:

    String* vector;
    size_t size;
    size_t capacity;

    void copyFrom(const StringVector& other);
    void copyFrom(const String* arr, size_t size);
    void resize();
    void checkAndResize();

public:
    StringVector();
    StringVector(const String* arr, size_t size);
    StringVector(const StringVector& other);
    StringVector& operator=(const StringVector& other);
    ~StringVector();

    void push_back(const std::string& str);
    void pop_back();
    void insert(size_t index, const std::string& str);
    void erase(size_t index);
    void clear();
    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;
    String& at(size_t index);
    const String& at(size_t index) const;
    bool empty() const;
    size_t size() const;

};