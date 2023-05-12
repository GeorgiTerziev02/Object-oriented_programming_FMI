#pragma once
#include "Vehicle.h"

class Tir: public Vehicle
{

private:
	static const size_t TIR_ALLOWED_DRIVING_PLACES_COUNT = 3;
	static MyString ALLOWED_DRIVING_PLACES[TIR_ALLOWED_DRIVING_PLACES_COUNT];
	static const size_t TIR_TIRES_AMOUNT = 18;

public:
	Tir();
	Tir(size_t passengersAmount, double averageSpeed);

	virtual const MyString* getAllowedDrivingPlaces() const override;
};

