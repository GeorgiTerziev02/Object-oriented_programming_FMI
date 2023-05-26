#pragma once
#include "CarPart.h"
#include "insufficient_fuel_error.h"
class FuelTank: public CarPart
{
	double capacity;
	double fullness;
public:
	FuelTank() = default;
	FuelTank(double initialCapacity);
	void use(double toUse);
	void fill(double toFill);
};

