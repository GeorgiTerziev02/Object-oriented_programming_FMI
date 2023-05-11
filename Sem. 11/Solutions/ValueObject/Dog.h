#pragma once
#include "ValueObject.h"

class Dog : public ValueObject {
private:
	size_t age;
public:
	bool equals(const ValueObject& lhs) const override;
	std::string getType() const override;
};