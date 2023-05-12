#include "Vehicle.h"

Vehicle::Vehicle(size_t tiresAmount, size_t passengersAmount, double averageSpeed)
	:tiresAmount(tiresAmount), passengersAmount(passengersAmount), averageSpeed(averageSpeed) {

	tires = new Tire[tiresAmount];
}

Vehicle::~Vehicle(){
	delete[] tires;
}

void Vehicle::setEngine(const Engine& newEngine) {
	this->engine = engine;
}

void Vehicle::changeTire(size_t index, const Tire& tire) {
	if (index >= tiresAmount) {
		throw std::length_error("Invalid index!");
	}
	tires[index] = tire;
}

double Vehicle::calculateMinutesForDistance(size_t distanceLength) const {
	return (distanceLength / averageSpeed) * 60;
}