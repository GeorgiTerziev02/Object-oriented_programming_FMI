#include "Car.h"

Car::Car() : Car(0) { }
Car::Car(size_t value): someValue(value) { }
size_t Car::getValue() const {
	return someValue;
}
void Car::setValue(size_t value) {
	someValue = value;
}