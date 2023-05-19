#pragma once

#include "../Controller/Controller.h"
#include "../Label/Label.h"
#include "../CheckBox/CheckBox.h"
#include "../RadioButton/RadioButton.h"

class ControllerCollection {
private:
    Controller** _controllers;
    size_t _size;
    size_t _capacity;

    void copyFrom(const ControllerCollection &other);
    void moveFrom(ControllerCollection &&other);
    void free();

    void resize();

public:
    ControllerCollection() = default;
    ControllerCollection(const ControllerCollection &other);
    ControllerCollection(ControllerCollection &&other);
    ControllerCollection &operator=(const ControllerCollection &other);
    ControllerCollection &operator=(ControllerCollection &&other);
    ~ControllerCollection();

    void addController(const Controller *controller);
//    void addLabel(const Label *label);
//    void addCheckBox(const CheckBox *checkBox);
//    void addRadioButton(const RadioButton *radioButton);

    void useDataDialog(unsigned index);

    const Controller &operator[](size_t index) const;
    Controller &operator[](size_t index);

};
