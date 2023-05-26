#include "GamingConsole.h"

void GamingConsole::printComputerType()const {
	std::cout << "This computer is gaming console" << std::endl;
}
MyString GamingConsole::getDevices()const {
	MyString result;
	for (int i = 0; i < 2; i++) {
		result += devices[i];
	}
	return result;
}