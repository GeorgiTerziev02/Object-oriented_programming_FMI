#include "../Autobus/Autobus.h"

const MyString Autobus::_roadType = "Everywhere";

const MyString &Autobus::getRoadType() const {
    return _roadType;
}
