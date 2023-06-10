#pragma once
#include "MyString.h"

class Computer
{
private:
	double processorPower;
	MyString videoCardModel;
	unsigned int powerSupply;
	unsigned int ram;

public:
	
	Computer(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram);
	virtual ~Computer();

	void setProcessorPower(double newProcessorPower);
	void setVideoCardModel(const MyString& newVideoCardModel);
	void setPowerSupply(unsigned int newPowerSupply);
	void setRam(unsigned int newRam);

	virtual void printTypeOfComputer() const = 0;
	virtual const MyString* getPeripherals() const = 0;
	virtual void printPeripherals() const = 0;
};

