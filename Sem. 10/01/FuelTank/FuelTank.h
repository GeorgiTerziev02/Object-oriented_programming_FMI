#pragma once
#include "MyString.h"

class insufficient_fuel_error : public std::logic_error 
{
public:
	insufficient_fuel_error(const char* msg) : std::logic_error(msg) {}
};

class FuelTank
{
	double capacity;
	double amount;
public:
	FuelTank();
	FuelTank(double capacity);
	double getAmount() const;
	double getCapacity() const;

	void use(double toUse);
	void fill(double toFill);
};

