//
// Created by Petar on 17.5.2023 г..
//

#include "CheckBox.h"

CheckBox::CheckBox(bool isOn, const char *data, double widthSize, double heightSize, double x, double y)
: Control(widthSize, heightSize, x, y), label(data){
    this->isOn = isOn;
}

CheckBox::CheckBox(bool isOn, const char *data) : CheckBox(isOn, data, 10, 10, 1, 1) {}

void CheckBox::setDataDialog() {
    label.setDataDialog(); // call the setDataDialog of the label
    isOn ? (isOn = false) : (isOn = true); // change the default seting for isOn
}

CheckBox::CheckBox() : CheckBox(false, "Default check box") {}

Control *CheckBox::clone() const {
    Control* newObj = new CheckBox(*this);
    return newObj;
}
