#include "AnimalFactory.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>

Animal* animalFactory(AnimalType type) {
	switch (type) {
	case AnimalType::Dog: return new Dog();
		break;
	case AnimalType::Cat: return new Cat();
		break;
	}

	throw std::invalid_argument("Invalid animal type");
}