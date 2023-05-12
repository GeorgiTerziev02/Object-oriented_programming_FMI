#include "Autobus.h"

MyString Autobus::ALLOWED_DRIVING_PLACES[] = { "city", "out of city", "highway" };

Autobus::Autobus() : Vehicle(AUTOBUS_TIRES_AMOUNT, 25, 70) {}

Autobus::Autobus(size_t passengersAmount, double averageSpeed) : Vehicle(AUTOBUS_TIRES_AMOUNT, passengersAmount, averageSpeed) {}

const MyString* Autobus::getAllowedDrivingPlaces() const {
	return ALLOWED_DRIVING_PLACES;
}