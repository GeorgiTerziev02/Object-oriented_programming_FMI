//
// Created by Petar on 6.5.2023 г..
//

#include "Car.h"
#include "insufficient_fuel_error.h"

Car::Car(const Engine &engine, const Tyres *carTyres, const Accumulator &accumulator, double tankCapacity,
         double mileage, unsigned int weight) : engine(engine), battery(accumulator), fuelTank(tankCapacity){
    for (int i = 0; i < TyresConsts::TYRES_COUNT; ++i) {
        this->carTyres[i] = carTyres[i];
    }
    setMileage(mileage);
    setWeight(weight);
}

const FuelTank &Car::getFuelTank() const {
    return this->fuelTank;
}

void Car::drive(double km, double litersByKm) {
    try {
        fuelTank.use(km * litersByKm);
        this->mileage+=km;
    }catch (insufficient_fuel_error& error){
        std::cout << error.getErrorMessage();
        throw;
    }
}

double Car::getMileage() const {
    return this->mileage;
}

unsigned Car::getWeight() const {
    return this->weight;
}

Car *dragRace(Car *car1, Car *car2) {
    bool isCar1Successful = true;
    bool isCar2Successful = true;
    try {
        car1->drive(0.4, 1);
    }catch (insufficient_fuel_error& error){
        isCar1Successful = false;
    }
    try {
        car2->drive(0.4, 1);
    }catch (insufficient_fuel_error& error){
        isCar2Successful = false;
    }
    if(isCar1Successful && isCar2Successful){ // successful race
        if(((double)car1->weight / car1->engine.getHorsePowers()) > ((double)car2->weight / car2->engine.getHorsePowers())){
            return car1;
        }
        return car2;
    } else if(isCar1Successful){
        return car1;
    }else if(isCar2Successful){
        return car2;
    }
    return nullptr;
}

void Car::setMileage(double mileage) {
    if(mileage < 0)
        throw std::invalid_argument("Mileage cannot be a negative number!");

    this->mileage = mileage;
}

void Car::setWeight(unsigned int weight) {
    this->weight = weight;
}
