//
// Created by Petar on 18.5.2023 г..
//

#include "RadioButton.h"


RadioButton::RadioButton(size_t optionsCount, size_t chosenOption) : RadioButton(optionsCount, chosenOption, 10, 10, 1, 1){}

RadioButton::RadioButton(size_t optionsCount, size_t chosenOption, double widthSize, double heightSize, double x,
                         double y)  : Control(widthSize, heightSize, x, y){
    this->optionsCount = optionsCount;
    options = new Label[optionsCount];
    for (int i = 0; i < optionsCount; ++i) {
        options[i].setDataDialog(); // initialize the every radio button with its label
    }
}

RadioButton::RadioButton() : RadioButton(1 , 1, 10 , 10 ,1 ,1) {}

void RadioButton::setDataDialog() {
    size_t optionToChange = 0;
    std::cout << "Choose number of option to be changed: "; // starts from 1
    std::cin.ignore();
    std::cin >> optionToChange;
    if(optionToChange - 1 > optionsCount){
        std::out_of_range("Error! No such an option!");
    }
    options[optionToChange-1].setDataDialog();
    std::cout << "Choose whether the option is chosen(y / n): ";
    MyString result;
    std::cin >> result;
    if(result[0] == 'y')
        this->indexOfChosenOption = optionToChange - 1;
}

size_t RadioButton::getChosenOption() const {
    return this->indexOfChosenOption  + 1; // +1 because we save the index but return the radio button stating from 1
}

void RadioButton::free() {
    delete[] this->options;
    this->options = nullptr;
    this->optionsCount = this->indexOfChosenOption = 0;
}

void RadioButton::copyFrom(const RadioButton &other) {
    this->optionsCount = other.optionsCount;
    this->indexOfChosenOption = other.indexOfChosenOption;
    this->options = new Label[optionsCount];
    for (int i = 0; i < optionsCount; ++i) {
        options[i] = other.options[i];
    }
}

void RadioButton::moveFrom(RadioButton &&other) {
    this->options = other.options;
    other.options = nullptr;
    other.optionsCount = other.indexOfChosenOption = 0;
}

RadioButton::RadioButton(const RadioButton &other) : Control(other){
    copyFrom(other);
}

RadioButton &RadioButton::operator=(const RadioButton &other) {
    if(this != &other){
        Control::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

RadioButton::RadioButton(RadioButton &&other) : Control(std::move(other)) {
    moveFrom(std::move(other));
}

RadioButton &RadioButton::operator=(RadioButton &&other) {
    if(this != &other){
        Control::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

RadioButton::~RadioButton() {
    free();
}

Control *RadioButton::clone() const {
    Control* newObj = new RadioButton(*this);
    return newObj;
}
