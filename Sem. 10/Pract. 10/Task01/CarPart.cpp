//
// Created by Petar on 3.5.2023 г..
//

#include "CarPart.h"
unsigned CarPart::countOfInstances = 0;

CarPart::CarPart(const MyString &manufacturerName, const MyString &description) {
    CarPart::countOfInstances++;
    this->id = countOfInstances;
    setManufacturerName(manufacturerName);
    setDescription(description);
}

unsigned CarPart::getId() const {
    return id;
}

const MyString &CarPart::getManufacturerName() const {
    return this->manufacturerName;
}

const MyString &CarPart::getDescription() const {
    return this->description;
}

void CarPart::setManufacturerName(const MyString &newName) {
    this->manufacturerName = newName;
}

void CarPart::setDescription(const MyString &newDescription) {
    this->description = newDescription;
}

CarPart::CarPart(MyString &&manufacturerName, MyString &&description)
: manufacturerName(std::move(manufacturerName)), description(std::move(description)) {
    CarPart::countOfInstances++;
    this->id = countOfInstances;
}

std::ostream& operator<<(std::ostream &ofs, const CarPart &part) {
    return ofs << "(" << part.id << ")" << " by " << part.manufacturerName << " - " << part.description;
}


