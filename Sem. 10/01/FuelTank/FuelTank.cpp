#include "FuelTank.h"
#include <iostream>

FuelTank::FuelTank() : FuelTank(0) {}

FuelTank::FuelTank(double capacity)
   :capacity(capacity), amount(capacity){}

double FuelTank::getAmount() const
{
	return amount;
}

double FuelTank::getCapacity() const
{
	return capacity;
}

void FuelTank::use(double toUse)
{
	if (toUse > amount)
	{
		throw insufficient_fuel_error("Insufficient fuel in tank.");
	}
	amount -= toUse;
}

void FuelTank::fill(double toFill)
{
	amount = std::min(amount + toFill, capacity);
}
