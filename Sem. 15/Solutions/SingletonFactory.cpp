#include "SingletonFactory.h"
#include <stdexcept>
#include <iostream>

SingletonFactory* SingletonFactory::instance = nullptr;

SingletonFactory::SingletonFactory() {
	std::cout << "Constructor" << std::endl;
}

SingletonFactory::~SingletonFactory() {
	std::cout << "Destructor" << std::endl;
}

SingletonFactory* SingletonFactory::getInstance() {
	// TODO: mutex lock!
	if (!instance) {
		instance = new SingletonFactory();
	}

	return instance;
}

void SingletonFactory::freeInstance() {
	delete instance;
	instance = nullptr;
}

Base* SingletonFactory::create(BaseType type) const {
	switch (type) {
	case BaseType::Der1: return new Der1(); break;
	case BaseType::Der2: return new Der2(); break;
	case BaseType::Der3: return new Der3(); break;
	default:throw std::exception("Invalid type");
	}
}