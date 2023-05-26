#pragma once
#include "Vehicle.h"
class Tir: public Vehicle
{
public:
	Tir(EngineType engine);
	virtual MyString whereYouCanDriveTheVehicle()const override;
};

