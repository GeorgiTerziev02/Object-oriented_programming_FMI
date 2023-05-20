//
// Created by Petar on 17.5.2023 г..
//

#ifndef PRACT12_CHECKBOX_H
#define PRACT12_CHECKBOX_H
#include "Label.h"

class CheckBox : public Control{
private:
    Label label;
    bool isOn;
public:
    CheckBox();
    CheckBox(bool isOn, const char* data, double widthSize, double heightSize, double x, double y);
    CheckBox(bool isOn, const char* data);
    void setDataDialog() override;
    Control * clone() const override;

};

#endif //PRACT12_CHECKBOX_H
