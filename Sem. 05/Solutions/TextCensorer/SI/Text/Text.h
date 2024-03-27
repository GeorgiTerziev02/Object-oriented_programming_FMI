#pragma once;

#include "../TextCensorer/TextCensorer.h"

// Version 1
class Text {
    // We are using aggregation for both the str and the censorer!
    // we don't manage the memory of the str, we just use it
    const char* str;
    
    // If we change it to Censor* we can then change
    // it every time with setter and also can have a default constructor
    const TextCensorer& censorer;
public:
    Text(const TextCensorer& textCensorer, const char* str);
    void print() const;
};

// Version 2
class TextWithCensorerPointer {
    const char* str;
    const TextCensorer* censorer;
public:
    TextWithCensorerPointer(const char* str, const TextCensorer* censorer = nullptr);
    void setCensorer(const TextCensorer* censorer);
    void print() const;
};