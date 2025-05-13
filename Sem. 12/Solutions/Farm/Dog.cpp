#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal(AnimalType::Dog) { }

void Dog::roar() const {
	std::cout << "Bark, bark" << std::endl;
}

Animal* Dog::clone() const {
	return new Dog(*this);
}