#pragma once
#include "Vehicle.h"
class Autobus:public Vehicle
{
public:
	Autobus(EngineType type);
	virtual MyString whereYouCanDriveTheVehicle()const override;
};

