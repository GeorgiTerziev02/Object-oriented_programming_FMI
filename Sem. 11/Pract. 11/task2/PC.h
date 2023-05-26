#pragma once
#include "Computer.h"
class PC:public Computer
{
	MyString devices[4] = { "Mouse","Keyboard","Microphone","HeadPhone" };
public:
	PC() = default;
	virtual void printComputerType()const override;
	virtual MyString getDevices()const override;
};

