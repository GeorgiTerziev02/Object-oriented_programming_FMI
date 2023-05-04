#include "AutomativeBattery.h"

AutomativeBattery::AutomativeBattery()
	:AutomativeBattery(0, "", "", 0, "") {}

AutomativeBattery::AutomativeBattery(unsigned id, const MyString& manufacturer, const MyString& description, unsigned capacity, const MyString& batteryId)
	: CarPart(id, manufacturer, description), capacity(capacity), batteryId(batteryId) {}

unsigned AutomativeBattery::getCapacity() const
{
	return capacity;
}

const MyString& AutomativeBattery::getBatteryId() const
{
	return batteryId;
}

void AutomativeBattery::print(std::ostream& os) const
{
	CarPart::print(os);
	os << " - " << capacity << "Ah";
}
