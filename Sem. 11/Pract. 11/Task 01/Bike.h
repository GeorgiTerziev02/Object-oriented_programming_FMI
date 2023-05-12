#pragma once
#include "Vehicle.h"

class Bike:public Vehicle
{

private:
	static const size_t BIKE_ALLOWED_DRIVING_PLACES_COUNT = 2;
	static MyString ALLOWED_DRIVING_PLACES[BIKE_ALLOWED_DRIVING_PLACES_COUNT];
	static const size_t BIKE_TIRES_AMOUNT = 2;

public:
	Bike();
	Bike(size_t passengersAmount, double averageSpeed);

	virtual const MyString* getAllowedDrivingPlaces() const override;
};