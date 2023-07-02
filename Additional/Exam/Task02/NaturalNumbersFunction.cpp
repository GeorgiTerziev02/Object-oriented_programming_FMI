#include "NaturalNumbersFunction.hpp"

#include <iostream>

NaturalNumbersFunction::NaturalNumbersFunction() {
	// Identity function: f(x) = x
	m_pFunc = [](unsigned value) { 
		return value;
	};
}

NaturalNumbersFunction::NaturalNumbersFunction(UnaryUnsignedFunction pFunc) : m_pFunc(pFunc) {
}

void NaturalNumbersFunction::SetFunction(UnaryUnsignedFunction pFunc) {
	m_pFunc = pFunc;
}

unsigned NaturalNumbersFunction::Eval(unsigned value) const {
	return m_pFunc(value);
}

bool CheckBounds(int& lowerBound, int& upperBound) {
	if (lowerBound > upperBound) { // Fix order of variables
		std::swap(lowerBound, upperBound);
	}

	if (upperBound < 0) { // All numbers are negative
		return false;
	}

	// We have checked that upperBound is >= 0,
	// If lowerBound is negative, adjust it to 0
	if (lowerBound < 0) { 
		lowerBound = 0;
	}

	return true;
}

unsigned NaturalNumbersFunction::CountFixedPoints(int lowerBound, int upperBound) const {
	if (!CheckBounds(lowerBound, upperBound)) {
		return 0; // return 0, because the provided interval is not valid.
	}

	unsigned counter = 0;
	for (unsigned i = lowerBound; i <= upperBound; ++i) {
		if (Eval(i) == i) { //f(k) = k
			++counter;
		}
	}

	return counter;
}

bool CheckFunctionsInInterval(const NaturalNumbersFunction& lhs, const NaturalNumbersFunction& rhs,
	int lowerBound, int upperBound) {
	if (!CheckBounds(lowerBound, upperBound)) {
		throw std::logic_error("Interval is not valid!");
	}

	for (unsigned i = lowerBound; i <= upperBound; ++i) {
		if (lhs.Eval(i) != rhs.Eval(i)) { //f(k) = k
			return false;
		}
	}

	return true;
}