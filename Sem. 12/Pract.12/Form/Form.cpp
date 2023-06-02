#include "Form.h"

Form::Form(size_t width, size_t height) : _size(width, height) {

}

bool Form::isInForm(size_t width, size_t height, size_t x, size_t y) {
    return width + x <= _size._width &&
           height + y <= _size._height;
}

void Form::setSize(size_t width, size_t height) {
    _size._width = width;
    _size._height = height;
}

void Form::setControllerSize(size_t index, size_t width, size_t height) {
    Controller &controller = _controllerCollection[index];
    if (!isInForm(width, height, controller.getCoordinates()._x, controller.getCoordinates()._y)) {
        throw std::invalid_argument("Controller goes out of form limits!");
    }

    _controllerCollection[index].setSize(width, height);
}

void Form::setControllerCoordinates(size_t index, size_t x, size_t y) {
    Controller &controller = _controllerCollection[index];
    if (!isInForm(controller.getSize()._width, controller.getSize()._height, x, y)) {
        throw std::invalid_argument("Controller goes out of form limits!");
    }

    _controllerCollection[index].setCoordinates(x, y);
}

void Form::change(size_t index) {
    _controllerCollection[index].setDataDialog();
}

void Form::addLabel(size_t x, size_t y, const char *text) {
    _controllerCollection.addController(new Label(x, y, text));
}

void Form::addCheckBox(size_t x, size_t y, const char *text) {
    _controllerCollection.addController(new CheckBox(x, y, text));
}

void Form::addRadioButton(size_t x, size_t y, const Vector<MyString> &options) {
    _controllerCollection.addController(new RadioButton(x, y, options));
}
