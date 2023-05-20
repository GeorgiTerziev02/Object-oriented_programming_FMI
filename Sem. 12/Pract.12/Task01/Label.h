//
// Created by Petar on 17.5.2023 г..
//

#ifndef PRACT12_LABEL_H
#define PRACT12_LABEL_H
#include "Control.h"
#include "MyString.h"

class Label: public Control{
private:
    MyString data;
public:
    Label();
    Label(const char* data, double widthSize, double heightSize, double x, double y);
    Label(const char* data);
    void setDataDialog() override;
    Control * clone() const override;
};

#endif //PRACT12_LABEL_H
