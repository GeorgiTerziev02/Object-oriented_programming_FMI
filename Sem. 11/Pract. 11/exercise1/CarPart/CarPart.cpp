#include "CarPart.h"

size_t CarPart::_globalId = 1;

CarPart::CarPart(const MyString &manufacturerName, const MyString &description) {
    _id = _globalId++;
    _manufacturerName = manufacturerName;
    _description = description;
}

size_t CarPart::getId() const {
    return _id;
}

const MyString &CarPart::getManufacturerName() const {
    return _manufacturerName;
}

const MyString &CarPart::getDescription() const {
    return _description;
}

void CarPart::setManufacturerName(const MyString &manufacturerName) {
    _manufacturerName = manufacturerName;
}

void CarPart::setDescription(const MyString &description) {
    _description = description;
}


std::ostream &operator<<(std::ostream &out, const CarPart &carPart) {
    return out << "(" << carPart._id << ")" << " by " << carPart._manufacturerName << " - " << carPart._description << " - ";
}
