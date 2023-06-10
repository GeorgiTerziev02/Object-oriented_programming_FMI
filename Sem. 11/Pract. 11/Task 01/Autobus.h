#pragma once
#include "Vehicle.h"

class Autobus: public Vehicle
{

private:
	static const size_t AUTOBUS_ALLOWED_DRIVING_PLACES_COUNT = 3;
	static MyString ALLOWED_DRIVING_PLACES[AUTOBUS_ALLOWED_DRIVING_PLACES_COUNT];
	static const size_t AUTOBUS_TIRES_AMOUNT = 6;

public:
	Autobus();
	Autobus(size_t passengersAmount, double averageSpeed);

	virtual const MyString* getAllowedDrivingPlaces() const override;
};

