//
// Created by Petar on 19.5.2023 г..
//

#ifndef PRACT12_FORM_H
#define PRACT12_FORM_H
#include "Control.h"

class Form{
private:
    Control** formControls;
    size_t controlsCount;
    size_t capacity;
    double formWidth;
    double formHeight;

public:
    Form();
    Form(double width, double height);
    Form(const Form& other);
    Form& operator=(const Form& other);
    Form(Form&& other) noexcept ;
    Form& operator=(Form&& other) noexcept ;
    ~Form();
    void addControl(ControlType type);
    void changeFormSize(double width, double height);
    void changeControlSizeByIndex(size_t index, double width, double height);
    void changeControlLocationByIndex(size_t index, double x ,double y);
    void changeControlData(size_t index);

private:
    void validateIndex(size_t index)const;
    void setWidth(double width);
    void setHeight(double height);
    void free();
    void copyfrom(const Form& other);
    void moveFrom(Form&& other);
    void resize();
};;

#endif //PRACT12_FORM_H
