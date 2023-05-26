#include "Laptop.h"

void Laptop::printComputerType()const {
	std::cout << "This computer is a laptop" << std::endl;
}
MyString Laptop::getDevices()const {
	MyString result;
	for (int i = 0; i < 3; i++) {
		result += devices[i];
	}
	retunr result;
}