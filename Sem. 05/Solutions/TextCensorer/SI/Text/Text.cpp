#include "Text.h"
#include <iostream>

Text::Text(const TextCensorer &textCensorer, const char *str)
    : censorer(textCensorer), str(str) {}

void Text::print() const {
    censorer.print(str);
}

TextWithCensorerPointer::TextWithCensorerPointer(const char *str, const TextCensorer *censorer = nullptr)
    : str(str), censorer(censorer) { }

void TextWithCensorerPointer::setCensorer(const TextCensorer *censorer) {
    this->censorer = censorer;
}
void TextWithCensorerPointer::print() const {
    if (!censorer) {
        std::cout << str << std::endl;
        return;
    }

    censorer->print(str);
}