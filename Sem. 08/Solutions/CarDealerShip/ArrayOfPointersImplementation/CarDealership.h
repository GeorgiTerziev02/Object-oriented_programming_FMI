#pragma once
#include "../Car/Car.h"

class CarDealership {
private:
	Car** cars;
	size_t count;
	size_t capacity;

	void resize();
public:
	CarDealership();
	CarDealership(const CarDealership& other);
	CarDealership& operator=(const CarDealership& other);
	~CarDealership();

	void addCar(const Car& newCar);
	void deleteAtIndex(size_t index);
	const Car& getCar(size_t index) const;

private:
	void free();
	void copyFrom(const CarDealership& other);
};
