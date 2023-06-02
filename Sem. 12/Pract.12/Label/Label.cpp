#include <cstring>
#include "Label.h"

void Label::setText(const char *text) {
    _text = MyString(text);
}

Label::Label(size_t x, size_t y, const char *text) : Controller(std::strlen(text), 1, x, y){
    setText(text);
}

void Label::setDataDialog() {
    char inputText[1024];
    std::cin >> inputText;

    setText(inputText);
}

Controller  *Label::clone() const {
    return new Label(*this);
}
