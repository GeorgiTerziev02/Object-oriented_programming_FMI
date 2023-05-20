#include <iostream>
#include "Form.h"
int main() {
    Form form;
    form.addControl(ControlType::Label);
    form.addControl(ControlType::RadioButton);
    form.addControl(ControlType::CheckBox);
    form.changeControlData(0);
    form.changeControlData(1);
    form.changeControlData(2);
}
