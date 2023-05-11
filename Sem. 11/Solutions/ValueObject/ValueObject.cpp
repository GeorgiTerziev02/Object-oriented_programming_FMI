#include "ValueObject.h"

bool operator==(const ValueObject& lhs, const ValueObject& rhs) {
	return lhs.equals(rhs);
}