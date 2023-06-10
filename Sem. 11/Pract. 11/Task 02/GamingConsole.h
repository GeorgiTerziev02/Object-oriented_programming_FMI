#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
private:

	static const unsigned int CONSOLE_PERIPHERALS_AMOUNT = 2;
	static MyString peripherals[CONSOLE_PERIPHERALS_AMOUNT];

public:

	GamingConsole(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram);

	void printTypeOfComputer() const override;
	const MyString* getPeripherals() const override;
	virtual void printPeripherals() const override;

};

