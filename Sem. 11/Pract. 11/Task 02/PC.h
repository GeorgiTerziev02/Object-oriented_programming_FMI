#pragma once
#include "Computer.h"

class PC : public Computer
{
private:

	static const unsigned int PC_PERIPHERALS_AMOUNT = 4;
	static MyString peripherals[PC_PERIPHERALS_AMOUNT];

public:

	PC(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram);

	void printTypeOfComputer() const override;
	const MyString* getPeripherals() const override;
	virtual void printPeripherals() const override;

};

