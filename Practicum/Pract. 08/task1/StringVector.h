#pragma once
#include "String.h"

class StringVector {
private:
    String* data;
    unsigned size_;
    unsigned capacity;

    void resize();
    void copyFrom(const StringVector& other);
    void free();

public:
    StringVector();
    StringVector(const StringVector& other);
    StringVector& operator=(const StringVector& other);
    ~StringVector();

    void push_back(const String& str);
    void pop_back();
    void insert(unsigned index, const String& str);
    void erase(unsigned index);
    void clear();

    String& at(unsigned index);
    const String& at(unsigned index) const;

    bool empty() const;
    unsigned size() const;
};
