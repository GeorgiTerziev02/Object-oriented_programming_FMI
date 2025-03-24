#include "TextCensorer.h"
#include <iostream>

namespace {
    bool isLower(char a) {
        return a >= 'a' && a <= 'z';
    }
};

void TextCensorer::printLetter(char a) const {
    std::cout << (isLower(a) && forbiddenLetters[a - 'a'] ? '*' : a);
}

void TextCensorer::addLetter(char a) {
    if (!isLower(a)) {
        return;
    }

    forbiddenLetters[a - 'a'] = true;
}

void TextCensorer::print(const char *str) const {
    if (!str) {
        return;
    }

    while (*str) {
        printLetter(*str);
        ++str;
    }

    std::cout << std::endl;
}