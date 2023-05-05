#include "FuelTank.h"

FuelTank::FuelTank() : CarPart("FuelTank Def Manu", "FuelTank Def Desc") {
    _capacity = _curFuel = 0;
}

FuelTank::FuelTank(const MyString &manufacturer, const MyString &description, double capacity) : CarPart(manufacturer, description) {
    _capacity = _curFuel = capacity;
}

void FuelTank::use(double toUse) {
    if (_curFuel - toUse > _capacity) {
        throw std::logic_error("Not enough fuel!");
    }

    _curFuel -= toUse;
}

void FuelTank::fill(double toFill) {
    _curFuel += toFill;

    if (_curFuel > _capacity) {
        _curFuel = _capacity;
    }
}
