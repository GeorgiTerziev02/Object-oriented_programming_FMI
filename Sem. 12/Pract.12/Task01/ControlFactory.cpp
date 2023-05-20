//
// Created by Petar on 19.5.2023 г..
//

#include "ControlFactory.h"
#include "Label.h"
#include "CheckBox.h"
#include "RadioButton.h"

Control *controlFactory(ControlType type) {
    switch (type) {
        case ControlType::Label:
            return new Label();
        case ControlType::CheckBox:
            return new CheckBox();
        case ControlType::RadioButton:
            return new RadioButton();
    }
    return nullptr;
}
