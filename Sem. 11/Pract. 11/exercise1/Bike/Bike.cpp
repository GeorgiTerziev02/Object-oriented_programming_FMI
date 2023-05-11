#include "../Bike/Bike.h"

const MyString Bike::_roadType = "Out of the City";

const MyString &Bike::getRoadType() const {
    return _roadType;
}
