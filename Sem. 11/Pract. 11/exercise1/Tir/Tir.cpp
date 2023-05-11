#include "../Tir/Tir.h"

const MyString Tir::_roadType = "Everywhere";

const MyString &Tir::getRoadType() const {
    return _roadType;
}
