//
// Created by Petar on 17.5.2023 г..
//
#include "Control.h"

void Control::setLocation(double x, double y) {
    // TODO - validation if needed
    location.x = x;
    location.y = y;
}

void Control::setSize(double x, double y) {
    // TODO - vaildation if needed
    this-> widthSize = x;
    this->heightSize = y;
}

Control::Control(double widthSize, double heightSize, double x, double y) {
    setSize(widthSize, heightSize);
    setLocation(x, y);
}

double Control::getControlWidth() const {
    return this->widthSize;
}

double Control::getControlHeight() const {
    return this->heightSize;
}

Control::Point::Point() : Point(0, 0){

}

Control::Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}
