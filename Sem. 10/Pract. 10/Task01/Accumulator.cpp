//
// Created by Petar on 5.5.2023 г..
//

#include "Accumulator.h"

Accumulator::Accumulator(const MyString &manufacturerName, const MyString &description, unsigned int capacity,
                         const MyString &batteryId) : CarPart(manufacturerName, description){
    setCapacity(capacity);
    setBatteryId(batteryId);
}

Accumulator::Accumulator(MyString &&manufacturerName, MyString &&description, unsigned int capacity,
                         const MyString &batteryId) : CarPart(std::move(manufacturerName), std::move(description)){

}

unsigned Accumulator::getCapacity() const {
    return this->capacity;
}

const MyString &Accumulator::getBateryId() const {
    return this->batteryId;
}

void Accumulator::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

void Accumulator::setBatteryId(const MyString &batteryId) {
    this->batteryId = batteryId;
}

std::ostream &operator<<(std::ostream &ofs, const Accumulator &accumulator) {
    operator<<(ofs, (CarPart&) accumulator);
    return ofs << accumulator.capacity << "Ah" << std::endl;
}
