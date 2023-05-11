#include "Dog.h"

bool Dog::equals(const ValueObject& lhs) const {
	if (getType() != lhs.getType()) {
		return false;
	}

	const Dog& otherDog = (const Dog&)lhs;

	return age == otherDog.age;
}

std::string Dog::getType() const {
	return "Dog";
}