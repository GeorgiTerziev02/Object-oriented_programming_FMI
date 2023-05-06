//
// Created by Petar on 6.5.2023 г..
//

#ifndef PRACT10_CAR_H
#define PRACT10_CAR_H
#include "Engine.h"
#include "Tyres.h"
#include "Accumulator.h"
#include "FuelTank.h"
#include "consts.h"

class Car{
private:
    Engine engine;
    Tyres carTyres[TyresConsts::TYRES_COUNT];
    Accumulator battery;
    FuelTank fuelTank;
    double mileage = 0.0;
    unsigned weight = 0;
public:
    Car() = delete;
    Car(const Engine& engine, const Tyres* carTyres, const Accumulator& accumulator, double tankCapacity, double mileage, unsigned weight);
    const FuelTank& getFuelTank()const;
    void drive(double km, double litersByKm);
    double getMileage()const;
    unsigned getWeight() const;
    friend Car* dragRace(Car* car1, Car* car2);

private:
    void setMileage(double mileage);
    void setWeight(unsigned weight);
};
Car* dragRace(Car* car1, Car* car2);

#endif //PRACT10_CAR_H
