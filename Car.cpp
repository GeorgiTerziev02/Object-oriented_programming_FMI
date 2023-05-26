#include "Car.h"

Car::Car(const FuelTank& fuelTank, const Engine& engine, Tire* tires,
	const Accumulator& accumulator, size_t mileage, size_t weight) {
	this->fuelTank = fuelTank;
	this->engine = engine;
	for (int i = 0; i < 4; i++) {
		this->tires[i] = tires[i];
	}
	this->accumulator = accumulator;
	this->mileage = mileage;
	this->weight;
}
const FuelTank& Car::getFuelTank()const {
	return fuelTank;
}
const Engine& Car::getEngine()const {
	return engine;
}
void Car::drive(double km) {
	mileage += km;
	fuelTank.use(km);
}
Car* dragRace(Car* c1, Car* c2) {
	return (c1->getEngine().getHorsePower()) > (c2->getEngine().getHorsePower()) ? c1 : c2;
}