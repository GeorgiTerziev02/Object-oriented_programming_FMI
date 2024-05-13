#include "Animal.h"

Animal::Animal(AnimalType type) : type(type)
{ }

AnimalType Animal::getType() const {
	return type;
}