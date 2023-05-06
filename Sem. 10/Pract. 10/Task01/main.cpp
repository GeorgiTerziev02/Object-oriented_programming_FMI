#include <iostream>
#include "Car.h"
int main() {
    Engine en1("Audi", "3.0TDI", 230);
    Tyres tyre1("Michelin", "summer front", 200, 60, 16);
    Tyres tyre2("Michelin", "summer front", 200, 60, 16);
    Tyres tyre3("Michelin", "summer rear", 210, 62, 17);
    Tyres tyre4("Michelin", "summer rear", 210, 62, 17);

    Accumulator battery("Powerzone", "12V", 40, "as123");

    Tyres firstCartyres[TyresConsts::TYRES_COUNT];
    firstCartyres[0] = tyre1;
    firstCartyres[1] = tyre2;
    firstCartyres[2] = tyre3;
    firstCartyres[3] = tyre4;

    Car car1(en1, firstCartyres, battery, 60, 70000, 1700);


    Engine en2("BMW", "2.0", 145);
    Tyres tyre12("Good year", "summer front", 190, 50, 14);
    Tyres tyre22("Good year", "summer front", 190, 50, 14);
    Tyres tyre32("Good year", "summer rear", 195, 62, 17);
    Tyres tyre42("Good year", "summer rear", 195, 62, 17);

    Accumulator battery2("Powerzone", "12V", 40, "as123");

    Tyres secondCartyres[TyresConsts::TYRES_COUNT];
    secondCartyres[0] = tyre12;
    secondCartyres[1] = tyre22;
    secondCartyres[2] = tyre32;
    secondCartyres[3] = tyre42;

    Car car2(en2, secondCartyres, battery2, 50, 90000, 1600);

    std::cout << dragRace(&car1, &car2)->getWeight();
}
