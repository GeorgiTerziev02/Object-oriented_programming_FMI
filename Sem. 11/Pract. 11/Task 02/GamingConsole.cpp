#include "GamingConsole.h"

MyString GamingConsole::peripherals[] = { "joystick", "monitor" };

GamingConsole::GamingConsole(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram)
	: Computer(processorPower, videoCardModel, powerSupply, ram) {}

void GamingConsole::printTypeOfComputer() const {
	std::cout << "Gaming console" << std::endl;
}

const MyString* GamingConsole::getPeripherals() const {
	return peripherals;
}

void GamingConsole::printPeripherals() const {
	for (size_t i = 0; i < CONSOLE_PERIPHERALS_AMOUNT; i++) {
		std::cout << peripherals[i] << " ";
	}
	std::cout << std::endl;
}