#include "Building.h"

bool Building::equals(const ValueObject& lhs) const {
	if (getType() != lhs.getType()) {
		return false;
	}

	const Building& otherBuilding = (const Building&)lhs;

	return height == otherBuilding.height;
}


std::string Building::getType() const {
	return "Building";
}