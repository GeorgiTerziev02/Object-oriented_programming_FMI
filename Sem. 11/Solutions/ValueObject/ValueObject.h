#pragma once
#include <string>

class ValueObject {
public:
	virtual bool equals(const ValueObject& lhs) const = 0;
	virtual std::string getType() const = 0;

	virtual ~ValueObject() = default;
};

bool operator==(const ValueObject& lhs, const ValueObject& rhs);