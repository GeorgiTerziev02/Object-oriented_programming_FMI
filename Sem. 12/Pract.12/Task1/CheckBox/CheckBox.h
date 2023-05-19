#pragma once

#include "../Controller/Controller.h"
#include "../MyString/MyString.h"

class CheckBox : public Controller {
private:
    MyString _text;
    bool _isOn;

public:
    CheckBox(size_t x, size_t y, const char *text);
    void setDataDialog() override;
    Controller *clone() const override;

    void setText(const char *text);

};
