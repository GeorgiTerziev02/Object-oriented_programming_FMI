#pragma once

#include "../Controller/Controller.h"
#include "../MyString/MyString.h"
#include "../Vector/Vector.hpp"

class RadioButton : public Controller {
private:
    Vector<MyString> _options;
    size_t _selectedIndex = 0;

public:
    RadioButton(size_t x, size_t y, const Vector<MyString> &options);
    void setDataDialog() override;
    Controller *clone() const override;

    void setOptionByIndex(unsigned index, const char *newOption);

};
