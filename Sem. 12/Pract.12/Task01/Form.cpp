//
// Created by Petar on 19.5.2023 г..
//

#include "Form.h"
#include "ControlFactory.h"

namespace {
    const size_t INITIAL_CAPACITY = 8;
    const double MIN_FORM_DIMENSION_SIZE = 100;
}

void Form::free() {
    for (int i = 0; i < this->controlsCount; ++i) {
        delete this->formControls[i];
    }
    delete[] this->formControls;
    this->controlsCount = this->capacity = 0;
}

void Form::copyfrom(const Form &other) {
    controlsCount = other.controlsCount;
    capacity = other.capacity;
    formControls = new Control * [capacity];
    for (int i = 0; i < controlsCount; ++i) {
        formControls[i] = other.formControls[i]->clone();
    }
}

void Form::moveFrom(Form &&other) {
    controlsCount = other.controlsCount;
    capacity = other.capacity;
    formControls = other.formControls;
    other.formControls = nullptr;
    other.controlsCount = other.capacity = 0;
}


Form::Form() {
    formWidth = MIN_FORM_DIMENSION_SIZE;
    formHeight = MIN_FORM_DIMENSION_SIZE;
    capacity = INITIAL_CAPACITY;
    controlsCount = 0;
    formControls = new Control * [capacity];
}

Form::Form(const Form &other) {
    copyfrom(other);
}

Form &Form::operator=(const Form &other) {
    if(this != &other){
        free();
        copyfrom(other);
    }
    return *this;
}

Form::Form(Form &&other) noexcept {
    moveFrom(std::move(other));
}

Form &Form::operator=(Form &&other) noexcept {
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Form::~Form() {
    free();
}

void Form::addControl(ControlType type) {
    if(controlsCount == capacity){
        resize();
    }
    formControls[controlsCount++] = controlFactory(type);
}

void Form::resize() {
    Control** temp = new Control * [capacity *= 2];
    for (int i = 0; i < controlsCount; ++i) {
        temp[i] = formControls[i];
    }
    delete[] formControls;
    formControls = temp;
}

Form::Form(double width, double height) : Form(){
    changeFormSize(width,height);
}

void Form::setWidth(double width) {
    if(width < MIN_FORM_DIMENSION_SIZE){
        std::invalid_argument("Too small width for the form");
    }
    this->formWidth = width;
}

void Form::setHeight(double height) {
    if(height < MIN_FORM_DIMENSION_SIZE){
        std::invalid_argument("Too small height for the form");
    }
    this -> formHeight = height;
}

void Form::changeFormSize(double width, double height) {
    setWidth(width);
    setHeight(height);
}

void Form::validateIndex(size_t index) const {
    if(index >= controlsCount){
        std::out_of_range("Error! Index is out of range!");
    }
}

void Form::changeControlSizeByIndex(size_t index, double width, double height) {
    validateIndex(index);
    if(width > this->formWidth || height > this->formHeight){
        std::invalid_argument("Error! Too big control size");
    }
    this->formControls[index]->setSize(width, height);
}

void Form::changeControlLocationByIndex(size_t index, double x, double y) {
    validateIndex(index);
    if((x + formControls[index]->getControlWidth() > formWidth) || (y + formControls[index]->getControlHeight() > formHeight)){
        std::invalid_argument("Error! You cannot change the location of the control outside of the form!");
    }
    formControls[index]->setLocation(x, y);
}

void Form::changeControlData(size_t index) {
    validateIndex(index);
    formControls[index]->setDataDialog();
}
