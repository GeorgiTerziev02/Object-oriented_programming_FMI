#include "Bike.h"

MyString Bike::ALLOWED_DRIVING_PLACES[] = { "city", "out of city" };

Bike::Bike() : Vehicle(BIKE_TIRES_AMOUNT, 1, 15) {}

Bike::Bike(size_t passengersAmount, double averageSpeed) : Vehicle(BIKE_TIRES_AMOUNT, passengersAmount, averageSpeed) {}

const MyString* Bike::getAllowedDrivingPlaces() const {
	return ALLOWED_DRIVING_PLACES;
}