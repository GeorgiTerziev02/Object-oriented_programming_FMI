#pragma once
#include "../Car/Car.h"

class CarDealership {
private:
	Car* cars;
	size_t count;
	size_t capacity;

	void resize();
public:
	CarDealership();
	CarDealership(const CarDealership&);
	CarDealership& operator=(const CarDealership&);
	~CarDealership();

	void addCar(const Car&);
	void deleteAtIndex(size_t index);
	const Car& getCar(size_t index) const;

private:
	void free();
	void copyFrom(const CarDealership&);
};
