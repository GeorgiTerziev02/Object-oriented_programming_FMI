#include "ControllerCollection.h"

void ControllerCollection::copyFrom(const ControllerCollection &other) {
    _size = other._size;
    _capacity = other._capacity;
    _controllers = new Controller *[_capacity];

    for (int i = 0; _size; ++i) {
        _controllers[i] = other._controllers[i]->clone();
    }
}

void ControllerCollection::moveFrom(ControllerCollection &&other) {
    _size = other._size;
    _capacity = other._capacity;

    _controllers = other._controllers;
    other._controllers = nullptr;
    other._size = other._capacity = 0;
}

void ControllerCollection::free() {
    for (int i = 0; _size; ++i) {
        delete _controllers[i];
    }
    delete[] _controllers;

    _controllers = nullptr;
    _size = _capacity = 0;
}

void ControllerCollection::resize() {
    Controller **temp = new Controller * [_capacity *= 2];
    for (int i = 0; i < _size; ++i) {
        temp[i] = _controllers[i]->clone();
    }

    delete[] _controllers;
    _controllers = temp;
}

ControllerCollection::ControllerCollection(const ControllerCollection &other) {
    copyFrom(other);
}

ControllerCollection::ControllerCollection(ControllerCollection &&other) {
    moveFrom(std::move(other));
}

ControllerCollection &ControllerCollection::operator=(const ControllerCollection &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

ControllerCollection &ControllerCollection::operator=(ControllerCollection &&other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

ControllerCollection::~ControllerCollection() {
    free();
}

void ControllerCollection::addController(const Controller *controller) {
    if (_size >= _capacity) {
        resize();
    }

    _controllers[_size++] = controller->clone();
}

/*
void ControllerCollection::addLabel(const Label *label) {
    addController(new Label(*label));
}

void ControllerCollection::addCheckBox(const CheckBox *checkBox) {
    addController(new CheckBox(*checkBox));
}

void ControllerCollection::addRadioButton(const RadioButton *radioButton) {
    addController(new RadioButton(*radioButton));
}
*/

void ControllerCollection::useDataDialog(unsigned int index) {
    _controllers[index]->setDataDialog();
}

const Controller &ControllerCollection::operator[](size_t index) const {
    return *_controllers[index];
}

Controller &ControllerCollection::operator[](size_t index) {
    return *_controllers[index];
}
