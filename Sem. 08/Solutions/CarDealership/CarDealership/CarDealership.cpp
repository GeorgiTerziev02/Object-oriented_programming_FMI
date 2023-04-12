#include "CarDealership.h"

const short INITIAL_CAPACITY = 4;

CarDealership::CarDealership() {
	count = 0;
	capacity = INITIAL_CAPACITY;
	cars = new Car* [capacity];
}

CarDealership::CarDealership(const CarDealership& other) {
	copyFrom(other);
}

CarDealership& CarDealership::operator=(const CarDealership& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

CarDealership::~CarDealership() {
	free();
}

void CarDealership::resize() {
	capacity *= 2;
	Car** temp = new Car* [capacity];
	for (size_t i = 0; i < count; i++) {
		temp[i] = cars[i];
	}

	delete[] cars;
	cars = temp;
}

void CarDealership::addCar(const Car& newCar) {
	if (count >= capacity) {
		resize();
	}

	cars[count++] = new Car(newCar);
}

void CarDealership::deleteAtIndex(size_t index) {
	if (index >= count) {
		throw "Invalid index";
	}

	delete cars[index];
	cars[index] = cars[count - 1];
	cars[--count] = nullptr;
}

const Car& CarDealership::getCar(size_t index) const {
	if (index >= count) {
		throw "Invalid index";
	}

	return *(cars[index]);
}

void CarDealership::free() {
	for (size_t i = 0; i < count; i++) {
		delete cars[i];
	}

	delete[] cars;
	capacity = count = 0;
}

void CarDealership::copyFrom(const CarDealership& other) {
	capacity = other.capacity;
	count = other.count;
	cars = new Car* [capacity];

	for (size_t i = 0; i < count; i++) {
		cars[i] = new Car(*(other.cars[i]));
	}
}