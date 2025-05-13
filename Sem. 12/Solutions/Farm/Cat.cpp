#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal(AnimalType::Cat) { }

void Cat::roar() const {
	std::cout << "meow, moew" << std::endl;
}

Animal* Cat::clone() const {
	return new Cat(*this);
}