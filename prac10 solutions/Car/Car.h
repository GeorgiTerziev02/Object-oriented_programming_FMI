#pragma once

#include <iostream>

#include "../Engine/Engine.h"
#include "../Tyre/Tyre.h"
#include "../CarBattery/CarBattery.h"
#include "../FuelTank/FuelTank.h"

class Car {
private:
    FuelTank _fuelTank;
    Engine *_engine;
    Tyre *_tyres[4];
    CarBattery *_carBattery;
    double _passedKilometers;
    size_t _weight;

public:
    Car(const FuelTank &fuelTank, Engine *engine,
        Tyre *tyre1, Tyre *tyre2, Tyre *tyre3, Tyre *tyre4,
        CarBattery *carBattery, size_t weight);

    const FuelTank& getFuelTank();

    void drive(double km);

    friend Car *dragRace(Car *car1, Car *car2);
};