#include "Car.h"

Car::Car(const FuelTank &fuelTank, Engine *engine, Tyre *tyre1, Tyre *tyre2, Tyre *tyre3,
         Tyre *tyre4, CarBattery *carBattery, size_t weight) {
    _fuelTank = fuelTank;
    _engine = engine;
    _tyres[0] = tyre1;
    _tyres[1] = tyre2;
    _tyres[2] = tyre3;
    _tyres[3] = tyre4;
    _carBattery = carBattery;
    _weight = weight;
}

const FuelTank &Car::getFuelTank() {
    return _fuelTank;
}

void Car::drive(double km) {
    try {
        _fuelTank.use(km);
        _passedKilometers += km;
    }
    catch(std::logic_error &exc) {
        std::cout << exc.what() << std::endl;
        throw;
    }
}
