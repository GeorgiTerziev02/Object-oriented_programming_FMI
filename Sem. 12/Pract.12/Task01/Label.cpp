//
// Created by Petar on 17.5.2023 г..
//
#include "Label.h"

void Label::setDataDialog() {
    std::cout << "Import value for the label: ";
    MyString result;
    std:: cin >> result;
    //TODO -> validation if needed
    this->data = std::move(result);
}

Label::Label(const char *data, double widthSize, double heightSize, double x, double y)
    : Control(widthSize, heightSize, x, y), data(data) {}

Label::Label(const char *data) : Label(data, 10, 10, 1, 1) {}

Label::Label() : Label("Default label") {

}

Control *Label::clone() const {
    Control* newObj = new Label(*this);
    return newObj;
}
