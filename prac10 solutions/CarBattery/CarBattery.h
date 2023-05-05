#pragma once
#include "../CarPart/CarPart.h"

class CarBattery : CarPart {
private:
    double _capacity;
    MyString _batteryId;

    void setCapacity(double capacity);
    void setBatteryId(const MyString &batteryId);

public:
    CarBattery() = delete;
    CarBattery(const MyString &manufacturerName, const MyString &description, double capacity, const MyString &batteryId);

    double getCapacity() const;
    const MyString &getBatteryId() const;

    friend std::ostream &operator<<(std::ostream &out, const CarBattery &carBattery);

};