#include "Computer.h"
#include "PC.h"
#include "Laptop.h"
#include "GamingConsole.h"
#include <iostream>

int main()
{

    PC pc(200, "video card", 50, 60);
    Computer* console = new GamingConsole(200, "console video card", 50, 60);
    Laptop laptop(300, "laptop video card", 45, 40);

    pc.printTypeOfComputer();
    pc.printPeripherals();
    console->printTypeOfComputer();
    console->printPeripherals();
    laptop.printTypeOfComputer();
    laptop.printPeripherals();

    delete console;
}

