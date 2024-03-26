#pragma once
#include "TextCensorer/TextCensorer.h"

namespace TextConstants {
    constexpr int BUFF_SIZE = 30;
};

class Text {
    char buff[TextConstants::BUFF_SIZE + 1] = "";
    // If we change it to Censor* we can then change
    // it every time with setter and also can have a default constructor
    TextCensorer& censorer;

    void setBuffer(const char* val);
public:
    Text(TextCensorer& textCensorer, const char* buff);
    void print() const;
};