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
	CarDealership(CarDealership&&) noexcept;
	CarDealership& operator=(const CarDealership&);
	CarDealership& operator=(CarDealership&&) noexcept;
	~CarDealership();

	void addCar(const Car&);
	void addCar(Car&&);
	void deleteAtIndex(size_t index);
	const Car& getCar(size_t index) const;

private:
	void free();
	void copyFrom(const CarDealership&);
	void moveFrom(CarDealership&&) noexcept;
};
