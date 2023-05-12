#include "Laptop.h"

MyString Laptop::peripherals[] = { "mouse pad", "keyboard", "monitor" };

Laptop::Laptop(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram)
	: Computer(processorPower, videoCardModel, powerSupply, ram) {}

void Laptop::printTypeOfComputer() const {
	std::cout << "Laptop" << std::endl;
}

const MyString* Laptop::getPeripherals() const {
	return peripherals;
}

void Laptop::printPeripherals() const {
	for (size_t i = 0; i < LAPTOP_PERIPHERALS_AMOUNT; i++) {
		std::cout << peripherals[i] << " ";
	}
	std::cout << std::endl;
}