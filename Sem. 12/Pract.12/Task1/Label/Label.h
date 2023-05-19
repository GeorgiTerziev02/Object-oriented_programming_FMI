#pragma once

#include "../Controller/Controller.h"
#include "../MyString/MyString.h"

class Label : public Controller {
private:
    MyString _text;

    void setText(const char *text);

public:
    Label(size_t x, size_t y, const char *text);
    void setDataDialog() override;
    Controller *clone() const override;

};
