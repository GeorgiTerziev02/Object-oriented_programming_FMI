#include "CarBattery.h"

void CarBattery::setCapacity(double capacity) {
    _capacity = capacity;
}

void CarBattery::setBatteryId(const MyString &batteryId) {
    _batteryId = batteryId;
}

CarBattery::CarBattery(const MyString &manufacturerName, const MyString &description, double capacity,
                       const MyString &batteryId) : CarPart(manufacturerName, batteryId) {
    setCapacity(capacity);
    setBatteryId(batteryId);
}

std::ostream &operator<<(std::ostream &out, const CarBattery &carBattery) {
    out << (CarPart &) carBattery;
    return out << carBattery._capacity << " Ah";
}
