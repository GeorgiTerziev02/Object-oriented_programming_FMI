#include "CarDealership.h"
#include <iostream>

namespace {
	constexpr size_t DEFAULT_CAPACITY = 4;
    constexpr char INDEX_OUT_OF_RANGE_EXCEPTION_MESSAGE[] = "Index out of range";
}

CarDealership::CarDealership(): count(0), capacity(DEFAULT_CAPACITY) {
	cars = new Car[capacity];
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

	cars[count++] = newCar;
}

void CarDealership::deleteAtIndex(size_t index) {
	if (index >= count) {
		throw std::out_of_range(INDEX_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	count--;
	cars[index] = cars[count];
	// TODO: maybe downsize
}


void CarDealership::resize() {
	capacity *= 2; // TODO: not optimal to be 2
	Car* temp = new Car[capacity];
	for (size_t i = 0; i < count; i++) {
		temp[i] = cars[i];
	}
	delete[] cars;
	cars = temp;
}

const Car& CarDealership::getCar(size_t index) const {
	if (index >= count) {
		throw std::out_of_range(INDEX_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	return cars[index];
}

void CarDealership::free() {
	delete[] cars;
	capacity = 0;
	count = 0;
}

void CarDealership::copyFrom(const CarDealership& other) {
	count = other.count;
	capacity = other.capacity;
	cars = new Car[capacity];

	for (size_t i = 0; i < count; i++) {
		cars[i] = other.cars[i];
	}
}