#pragma once
#include "Computer.h"
class GamingConsole:public Computer
{
	MyString devices[2]{ "Gamepad","Monitor" };
public:
	virtual void printComputerType()const override;
	virtual MyString getDevices()const override;
};

