#include "Vehicle.h"

void Vehicle::copyFrom(const Vehicle &other) {
    _tyreCount = other._tyreCount;
    _tyres = new Tyre[_tyreCount];
    for (int i = 0; i < _tyreCount; ++i) {
        _tyres[i] = other._tyres[i];
    }
    _engineType = other._engineType;
    _passengersCount = other._passengersCount;
    _averageSpeed = other._averageSpeed;
}

void Vehicle::moveFrom(Vehicle &&other) {
    _tyreCount = other._tyreCount;
    _tyres = other._tyres;
    other._tyres = nullptr;
    _engineType = other._engineType;
    _passengersCount = other._passengersCount;
    _averageSpeed = other._averageSpeed;
}

void Vehicle::free() {
    delete[] _tyres;
    _tyres = nullptr;
    _tyreCount = _passengersCount = _averageSpeed = 0;
}

//Vehicle::Vehicle() {
//}

Vehicle::Vehicle(const Vehicle &other) {
    copyFrom(other);
}

Vehicle::Vehicle(Vehicle &&other) noexcept {
    moveFrom(std::move(other));
}

Vehicle &Vehicle::operator=(const Vehicle &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    
    return *this;
}

Vehicle &Vehicle::operator=(Vehicle &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Vehicle::~Vehicle() {
    free();
}

Vehicle::Vehicle(const Tyre *tyres, size_t tyreCount, EngineType engineType, size_t passengersCount, double averageSpeed) {
    for (int i = 0; i < tyreCount; ++i) {
        _tyres[i] = tyres[i];
    }

    _tyreCount = tyreCount;
    _engineType = engineType;
    _passengersCount = passengersCount;
    _averageSpeed = averageSpeed;
}

void Vehicle::changeEngineType(EngineType _newEngineType) {
    _engineType = _newEngineType;
}

double Vehicle::calculateTimeToGetFromAToB(const Point &a, const Point &b) const {
    // TODO : calc distance between 2 points and find time needed
    return 0;
}

void Vehicle::changeTyre(const Tyre &newTyre, size_t index) {
    if (index < 0 && index > _tyreCount) {
        throw std::invalid_argument("Index is out of bound!");
    }

    _tyres[index] = newTyre;
}

