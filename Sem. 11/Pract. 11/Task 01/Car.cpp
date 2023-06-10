#include "Car.h"

MyString Car::ALLOWED_DRIVING_PLACES[] = { "city", "out of city", "highway" };

Car::Car(): Vehicle(CAR_TIRES_AMOUNT, 5, 90) {}

Car::Car(size_t passengersAmount, double averageSpeed): Vehicle(CAR_TIRES_AMOUNT, passengersAmount, averageSpeed) {}

const MyString* Car::getAllowedDrivingPlaces() const {
	return ALLOWED_DRIVING_PLACES;
}