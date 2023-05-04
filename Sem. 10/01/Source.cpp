#include <iostream>
#include "Car.h"

void testCar() 
{
   
    Car car1;
    
    FuelTank fuelTank(1000.0);
    Engine engine(1, "Ford", "V8", 300, 5.0);
    Tyre tyres[] = { Tyre(1, "Michelin", "Summer", 225, 45, 17, 1.0),
                      Tyre(2, "Michelin", "Summer", 225, 45, 17, 1.0),
                      Tyre(3, "Michelin", "Summer", 225, 45, 17, 1.0),
                      Tyre(4, "Michelin", "Summer", 225, 45, 17, 1.0) };
    AutomativeBattery battery(1, "Bosch", "Lead-Acid", 70, "ABC123");
    Car car2(fuelTank, engine, tyres, battery, 0, 1500);


    car2.drive(100.0);
    std::cout << car2.getKmDriven() << std::endl;

    Car car3 = car2;
    std::cout << car3.getWeigth() << std::endl;

    Car car4;
    car4 = car3;
    std::cout << car4.getTyres()[1].getProfile() << std::endl;

    Car car5 = car4;
    std::cout << car5.getBattery().getBatteryId() << std::endl;

    Car car6;
    car6 = std::move(car5);
    std::cout << car6.getEngine().getFuelConsumation() << std::endl;

    Car* winner = car1.dragRace(&car2, &car3);
    std::cout << winner->getWeigth() << std::endl;
}

void testAutomativeBattery() 
{
    AutomativeBattery battery1;
    AutomativeBattery battery2(1, "Bosch", "Lead-Acid", 70, "ABC123");

    std::cout << battery2.getBatteryId() << std::endl;

    battery1 = battery2;
    std::cout << battery1.getCapacity() << std::endl;

    AutomativeBattery battery3 = std::move(battery2);
}


int main()
{
    //testCar();
    testAutomativeBattery();
}
