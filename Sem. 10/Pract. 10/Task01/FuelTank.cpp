//
// Created by Petar on 6.5.2023 г..
//

#include "FuelTank.h"
#include "iostream"
#include "insufficient_fuel_error.h"

double FuelTank::getTankCapacity() const {
    return tankCapacity;
}

double FuelTank::getTankFull() const {
    return tankFull;
}

void FuelTank::setTankCapacity(double tankCapacity) {
    if(tankCapacity < 0){
        throw std::invalid_argument("Tank capacity cannot be a negative number");
    }
    this-> tankCapacity = tankCapacity;
}

void FuelTank::setTankFull(double tankFull) {
    if(tankFull < 0){
        throw std::invalid_argument("Tank fullness cannot be a negative number");
    }
    this->tankFull = tankFull;
}

FuelTank::FuelTank(double tankCapacity) {
    setTankCapacity(tankCapacity);
    setTankFull(tankCapacity);
}

void FuelTank::use(double toUse) {
    if(toUse > this->tankFull)
        throw insufficient_fuel_error("Not enough fuel!");
    this->tankFull-=toUse;
}

void FuelTank::fill(double toFill) {
    if(toFill + this->tankFull >=this->tankCapacity)
        this->tankFull = this->tankCapacity;
    else
        this->tankFull+=toFill;
}
