#pragma once
#include "Computer.h"
class Laptop: public Computer
{
	MyString devices[3]{ "mouse pad","keyboard","monitor" };
public:
	Laptop() = default;
	virtual void printComputerType()const override;
	virtual MyString getDevices()const override;
};

