#include "PrimeIterator.h"
#include <cmath>

// Anonymous namespace is used to define constants, functions, classes, etc.
// that are only visible in the current compilation unit.
// They can't be accessed from other .cpp!
namespace {
    // copied from introduction to programming
    bool isPrime(unsigned int number) {
    	if (number == 2) {
    		return true;
    	}

    	if (number == 1 || number % 2 == 0) {
    		return false;
    	}

    	double sqrtN = sqrt(number);
    	for (int i = 3; i <= sqrtN; i += 2) {
    		if (number % i == 0) {
    			return false;
    		}
        }
        return true;
    }
}

PrimeIterator& PrimeIterator::goToNext() {
    //todo: todo validate edge cases => ULLONG_MAX
    while (!isPrime(++_value)) {}
    return *this;
}
	
PrimeIterator& PrimeIterator::goToPrev() {
    //todo: todo validate edge cases => 0, 1
    if (_value != 2) {
        while (!isPrime(--_value)) {}
    }
    return *this;
}

PrimeIterator::PrimeIterator() : PrimeIterator(2) { }

PrimeIterator::PrimeIterator(size_t value) {
    setValue(value);
}

size_t PrimeIterator::getValue() const {
    return _value;
}

void PrimeIterator::setValue(size_t value) {
    _value = isPrime(value) ? value : 2;
}

PrimeIterator& PrimeIterator::operator++() {
    return goToNext();
}

PrimeIterator PrimeIterator::operator++(int) {
    PrimeIterator oldCopy(*this);
    goToNext();
    return oldCopy;
}

PrimeIterator& PrimeIterator::operator--() {
    return goToPrev();
}

PrimeIterator PrimeIterator::operator--(int) {
    PrimeIterator oldCopy(*this);
    goToPrev();
    return oldCopy;
}

unsigned PrimeIterator::operator*() const {
    return _value;
}

bool operator==(const PrimeIterator & lhs, const PrimeIterator & rhs) {
    return lhs.getValue() == rhs.getValue();
}

bool operator!=(const PrimeIterator& lhs, const PrimeIterator& rhs) {
    return lhs.getValue() != rhs.getValue();
}
