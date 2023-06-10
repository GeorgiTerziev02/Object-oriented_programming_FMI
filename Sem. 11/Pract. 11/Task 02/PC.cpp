#include "PC.h"
#include<iostream>

MyString PC::peripherals[] = { "mouse", "keyboard", "microphone", "headphones" };

PC::PC(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram)
	: Computer(processorPower, videoCardModel, powerSupply, ram) {}

void PC::printTypeOfComputer() const {
	std::cout << "PC" << std::endl;
}

const MyString* PC::getPeripherals() const {
	return peripherals;
}

void PC::printPeripherals() const {
	for (size_t i = 0; i < PC_PERIPHERALS_AMOUNT; i++) {
		std::cout << peripherals[i] << " ";
	}
	std::cout << std::endl;
}