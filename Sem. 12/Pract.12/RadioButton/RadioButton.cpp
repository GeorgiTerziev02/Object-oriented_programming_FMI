#include "RadioButton.h"

RadioButton::RadioButton(size_t x, size_t y, const Vector <MyString> &options) : Controller(1, options.getSize(), x, y) {
    _options = options;
}

void RadioButton::setDataDialog() {
    char inputText;
    std::cin >> inputText;

    unsigned newSelectedIndex = inputText - '0' - 1;

    if (newSelectedIndex >= _options.getSize()) {
        throw "No such option!";
    }

    _selectedIndex = newSelectedIndex;
}

Controller *RadioButton::clone() const {
    return new RadioButton(*this);
}

void RadioButton::setOptionByIndex(unsigned int index, const char *newOption) {
    _options[index] = MyString(newOption);
}
