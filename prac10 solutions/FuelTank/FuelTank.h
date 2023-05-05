#pragma once
#include <iostream>

#include "../CarPart/CarPart.h"

class FuelTank : CarPart {
private:
    double _curFuel;
    double _capacity;

public:
    FuelTank();
    FuelTank(const MyString &manufacturer, const MyString &description, double capacity);

    void use(double toUse);
    void fill(double toFill);

};