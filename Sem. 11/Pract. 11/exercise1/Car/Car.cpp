#include "../Car/Car.h"

//Car::Car(const Tyre *tyres, size_t tyreCount, EngineType engineType, size_t passengersCount, double averageSpeed, const MyString &roadType)
//        : Vehicle(tyres, tyreCount, engineType, passengersCount, averageSpeed) {
//    _roadType = roadType;
//}

//const MyString &Car::getRoadType() const {
//    return _roadType;
//}

const MyString Car::_roadType = "City Only";

const MyString &Car::getRoadType() const {
    return _roadType;
}
