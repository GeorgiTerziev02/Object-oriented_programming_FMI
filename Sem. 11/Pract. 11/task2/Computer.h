#pragma once
#include "MyString.h"
class Computer
{
	double power;
	MyString GPUModel;
	size_t powerSupply;
	size_t RAM;
public:
	void setGPU(const MyString& newModel);
	void setPowerSupply(size_t newPowerSupply);
	void setRAM(size_t newRAM);
	void setPower(double newPower);
	virtual void printComputerType()const=0;
	virtual MyString getDevices()const = 0;
	virtual ~Computer() = default;
};

