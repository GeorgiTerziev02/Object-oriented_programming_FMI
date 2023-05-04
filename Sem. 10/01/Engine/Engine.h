#pragma once
#include "CarParts.h"
class Engine : CarPart
{
private:
	unsigned hP;
	double fuelConsumation;
public:
	Engine();
	Engine(unsigned id, const MyString& manufacturer, const MyString& description, unsigned hP, double fuelConsumed);
	unsigned getHp() const;
	double getFuelConsumation() const;

	void print(std::ostream& os) const override;
};

