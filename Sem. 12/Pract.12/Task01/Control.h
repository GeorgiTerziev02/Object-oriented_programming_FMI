//
// Created by Petar on 17.5.2023 г..
//

#ifndef PRACT12_CONTROL_H
#define PRACT12_CONTROL_H
#include "iostream"

enum class ControlType{
    Label,
    CheckBox,
    RadioButton
};

class Control{
private:
    double widthSize;
    double heightSize;
    struct Point{
        double x;
        double y;
        Point();
        Point(double x, double y);
    };
    Point location;
public:
    Control(double widthSize, double heightSize, double x, double y);
    virtual void setDataDialog() = 0;
    virtual Control* clone() const = 0;
    void setLocation(double x, double y);
    void setSize(double x, double y);
    double getControlWidth() const;
    double getControlHeight() const;
    virtual ~Control() = default;
};

#endif //PRACT12_CONTROL_H
