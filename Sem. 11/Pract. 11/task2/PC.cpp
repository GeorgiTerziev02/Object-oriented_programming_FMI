#include "PC.h"

void PC::printComputerType()const {
	std::cout << "This compuer is PC" << std::endl;
}
MyString PC::getDevices()const {
	MyString result;
	for (int i = 0; i < 4; i++) {
		 result+=devices[i];
	}
	return result;
}