#pragma once
#include "Vehicle.h"
class Car: public Vehicle
{
public:
	Car();
	virtual MyString whereYouCanDriveTheVehicle() const override;
};

