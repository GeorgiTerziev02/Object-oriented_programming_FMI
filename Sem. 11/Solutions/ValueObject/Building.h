#pragma once

#include "ValueObject.h"

class Building : public ValueObject {
private:
	size_t height;
public:
	bool equals(const ValueObject& lhs) const override;
	std::string getType() const override;
};

