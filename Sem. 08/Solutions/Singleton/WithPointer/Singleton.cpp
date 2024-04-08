#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() : dummy(5) {}

int Singleton::getDummy() const {
	return dummy;
}

void Singleton::print() {
	std::cout << "Hello";
}

Singleton& Singleton::getInstance() {
	if (!instance) {
		instance = new Singleton();
	}

	return *instance;
}
