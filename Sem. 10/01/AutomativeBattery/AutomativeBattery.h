#pragma once
#include "CarParts.h"
#include "MyString.h"
class AutomativeBattery : CarPart
{
private:
	unsigned capacity;
    MyString batteryId;
public:
	AutomativeBattery();
	AutomativeBattery(unsigned id, const MyString& manufacturer, const MyString& description, unsigned capacity, const MyString& batteryId);
	unsigned getCapacity() const;
	const MyString& getBatteryId() const;

	void print(std::ostream& os) const override;
};

