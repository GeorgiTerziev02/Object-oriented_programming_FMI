#pragma once
#include "Vehicle.h"
class Bike:public Vehicle
{
public:
	Bike();
	virtual MyString whereYouCanDriveTheVehicle()const override;
};

