#include "Singleton.h"
#include <iostream>

Singleton::Singleton() : dummy(5) {}

int Singleton::getDummy() const {
	return dummy;
}

void Singleton::print() {
	std::cout << "Hello";
}

Singleton& Singleton::getInstance() {
	static Singleton instance;
	return instance;
}
