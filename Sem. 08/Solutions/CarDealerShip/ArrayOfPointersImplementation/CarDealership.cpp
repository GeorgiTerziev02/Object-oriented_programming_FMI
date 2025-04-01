#include "CarDealership.h"
#include <iostream>

namespace {
	constexpr size_t DEFAULT_CAPACITY = 4;
}

CarDealership::CarDealership(): count(0), capacity(DEFAULT_CAPACITY) {
	cars = new Car*[capacity];
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

void CarDealership::addCar(const Car& newCar) {
	if (count >= capacity) {
		resize();
	}

	cars[count++] = new Car(newCar);
}

void CarDealership::deleteAtIndex(size_t index) {
	if (index >= count) {
		throw std::out_of_range("Invalid index");
	}

	// TODO: maybe downsize
	delete cars[index];
	count--;
	cars[index] = cars[count];
	cars[count] = nullptr;
}


void CarDealership::resize() {
	capacity *= 2;
	Car** temp = new Car * [capacity] {};
	for (size_t i = 0; i < count; i++) {
		temp[i] = cars[i];
	}
	delete[] cars;
	cars = temp;
}

const Car& CarDealership::getCar(size_t index) const {
	if (index >= count) {
		throw std::out_of_range("Invalid index");
	}

	return *cars[index];
}

void CarDealership::free() {
	for (size_t i = 0; i < count; i++) {
		delete cars[i];
	}
	delete[] cars;
	capacity = 0;
	count = 0;
}

void CarDealership::copyFrom(const CarDealership& other) {
	count = other.count;
	capacity = other.capacity;
	cars = new Car*[capacity];

	for (size_t i = 0; i < count; i++) {
		cars[i] = new Car(*other.cars[i]);
	}
}