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
	CarDealership(CarDealership&& other) noexcept;
	CarDealership& operator=(const CarDealership& other);
	CarDealership& operator=(CarDealership&& other) noexcept;
	~CarDealership();

	void addCar(const Car& newCar);
	void addCar(Car&& newCar);
	void deleteAtIndex(size_t index);
	const Car& getCar(size_t index) const;

private:
	void free();
	void copyFrom(const CarDealership& other);
	void moveFrom(CarDealership&& other) noexcept;
};
