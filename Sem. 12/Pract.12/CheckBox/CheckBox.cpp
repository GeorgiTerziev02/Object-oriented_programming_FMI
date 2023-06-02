#include <cstring>
#include "CheckBox.h"

void CheckBox::setText(const char *text) {
    _text = MyString(text);
}

CheckBox::CheckBox(size_t x, size_t y, const char *text) : Controller(1, std::strlen(text), x, y) {
    setText(text);
}

void CheckBox::setDataDialog() {
    char inputText[1024];
    std::cin >> inputText;

    _isOn = std::strcmp(inputText, "on") == 0;
}

Controller *CheckBox::clone() const {
    return new CheckBox(*this);
}
