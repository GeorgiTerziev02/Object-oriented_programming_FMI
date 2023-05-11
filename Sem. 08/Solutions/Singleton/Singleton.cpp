#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {
    std::cout << "Constructor" << std::endl;
}

Singleton::~Singleton(){
    std::cout << "Destructor" << std::endl;
}

Singleton* Singleton::getInstance() {
	if (instance == nullptr) {
		instance = new Singleton();
	}

	return instance;
}

void Singleton::freeInstance() {
	delete instance;
	instance = nullptr;
}