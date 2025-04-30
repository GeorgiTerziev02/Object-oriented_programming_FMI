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

CarDealership::CarDealership(CarDealership&& other) noexcept {
	moveFrom(std::move(other));
}

CarDealership& CarDealership::operator=(const CarDealership& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

CarDealership& CarDealership::operator=(CarDealership&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
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

void CarDealership::addCar(Car&& newCar) {
	if (count >= capacity) {
		resize();
	}

	cars[count++] = new Car(std::move(newCar));
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

void CarDealership::moveFrom(CarDealership&& other) noexcept {
	count = other.count;
	capacity = other.capacity;
	cars = other.cars;

	other.count = 0;
	other.capacity = 0;
	other.cars = nullptr;
}