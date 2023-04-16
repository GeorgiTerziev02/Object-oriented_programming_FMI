#include "Car.h"

Car::Car(size_t number) {
	setNumber(number);
}

size_t Car::getNumber() const {
	return number;
}

void Car::setNumber(size_t number) {
	this->number = number;
}