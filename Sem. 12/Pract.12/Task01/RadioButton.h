//
// Created by Petar on 18.5.2023 г..
//

#ifndef PRACT12_RADIOBUTTON_H
#define PRACT12_RADIOBUTTON_H
#include "Label.h"
#include "MyString.h"
class RadioButton : public Control{
private:
    Label* options = nullptr;
    size_t optionsCount;
    size_t indexOfChosenOption;
public:
    //BIG SIX for the options
    RadioButton();
    RadioButton(size_t optionsCount, size_t chosenOption, double widthSize, double heightSize, double x, double y);
    RadioButton(size_t optionsCount, size_t chosenOption);
    RadioButton(const RadioButton& other);
    RadioButton& operator=(const RadioButton& other);
    RadioButton(RadioButton&& other);
    RadioButton& operator=(RadioButton&& other);
    void setDataDialog() override;
    Control * clone() const override;
    size_t getChosenOption() const;
    ~RadioButton();

private:
    void free();
    void copyFrom(const RadioButton& other);
    void moveFrom(RadioButton&& other);
};

#endif //PRACT12_RADIOBUTTON_H
