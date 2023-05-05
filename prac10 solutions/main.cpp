#include <iostream>
#include "Engine/Engine.h"
#include "Tyre/Tyre.h"
#include "CarBattery/CarBattery.h"

#include "Car/Car.h"

Car* dragRace(Car* car1, Car* car2) {
    try {
        (*car1).drive(0.4);
    }
    catch (std::logic_error &exc) {
        try {
            (*car2).drive(0.4);
            return car2;
        }
        catch (std::logic_error &exc) {
            return nullptr;
        }
    }

    try {
        (*car2).drive(0.4);
    }
    catch (std::logic_error &exc) {
        return car1;
    }

    double car1Coef = car1->_engine->getHorsePower() / (double) car1->_weight;
    double car2Coef = car2->_engine->getHorsePower() / (double) car2->_weight;

    if (car1Coef > car2Coef) {
        return car1;
    }
    return car2;
}

int main() {
    Engine e1("Manu2.1", "Desc2.1", 100);
    Engine e2("Manu2.2", "Desc2.2", 200);

    Tyre  t1("Manu3.1", "Desc3.1", 156, 31, 20);
    Tyre  t2("Manu3.1", "Desc3.1", 156, 31, 20);
    Tyre  t3("Manu3.1", "Desc3.1", 156, 31, 20);
    Tyre  t4("Manu3.1", "Desc3.1", 156, 31, 20);

    CarBattery cb1("Manu4", "Desc4", 156, "Hello");

    FuelTank ft1("Manu5.1", "Desc5.1", 100);
    FuelTank ft2("Manu5.2", "Desc5.2", 100);

    Car car1(ft1, &e1, &t1, &t2, &t3, &t4, &cb1, 5001);
    Car car2(ft2, &e2, &t1, &t2, &t3, &t4, &cb1, 5000);

    dragRace(&car1, &car2);

    return 0;
}
