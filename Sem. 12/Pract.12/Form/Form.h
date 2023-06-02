#pragma once

#include "../ControllerCollection/ControllerCollection.h"

class Form {
private:
    ControllerCollection _controllerCollection;
    Size _size;

    bool isInForm(size_t width, size_t height, size_t x, size_t y);

public:
    Form(size_t width, size_t height);

    void addLabel(size_t x, size_t y, const char *text);
    void addCheckBox(size_t x, size_t y, const char *text);
    void addRadioButton(size_t x, size_t y, const Vector<MyString> &options);

    void setSize(size_t width, size_t height);
    void setControllerSize(size_t index, size_t width, size_t height);
    void setControllerCoordinates(size_t index, size_t x, size_t y);

    void change(size_t index);

};