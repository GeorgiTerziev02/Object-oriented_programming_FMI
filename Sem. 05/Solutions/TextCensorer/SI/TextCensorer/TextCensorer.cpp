#include "TextCensorer.h"
#include <iostream>

TextCensorer::TextCensorer(bool (*shouldCensor)(char)) : shouldCensor(shouldCensor) {}

void TextCensorer::print(const char *str) const {
    if (!str) {
        return;
    }

    while (*str) {
        print(*str);
        ++str;
    }

    std::cout << std::endl;
}

void TextCensorer::print(char a) const {
    std::cout << (shouldCensor(a) ? '*' : a);
}