#pragma once
#include "Vehicle.h"

class Car: public Vehicle
{
private:
	static const size_t CAR_ALLOWED_DRIVING_PLACES_COUNT = 3;
	static MyString ALLOWED_DRIVING_PLACES[CAR_ALLOWED_DRIVING_PLACES_COUNT];
	static const size_t CAR_TIRES_AMOUNT = 4;

public:
	Car();
	Car(size_t passengersAmount, double averageSpeed);

	virtual const MyString* getAllowedDrivingPlaces() const override;
};