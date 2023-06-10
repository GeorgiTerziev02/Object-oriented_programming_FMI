#include "Tir.h"

MyString Tir::ALLOWED_DRIVING_PLACES[] = { "city", "out of city", "highway" };

Tir::Tir() : Vehicle(TIR_TIRES_AMOUNT, 2, 70) {}

Tir::Tir(size_t passengersAmount, double averageSpeed) : Vehicle(TIR_TIRES_AMOUNT, passengersAmount, averageSpeed) {}

const MyString* Tir::getAllowedDrivingPlaces() const {
	return ALLOWED_DRIVING_PLACES;
}