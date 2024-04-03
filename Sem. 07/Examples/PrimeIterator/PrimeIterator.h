#pragma once
#include <iostream>
#include <fstream>
class PrimeIterator {
private:
	size_t _value;
    
	PrimeIterator& goToNext();
	PrimeIterator& goToPrev();

public:
	PrimeIterator(size_t value);
	PrimeIterator();

	size_t getValue() const;
	void setValue(size_t value);

	PrimeIterator& operator++();
	PrimeIterator operator++(int);

	PrimeIterator& operator--();
	PrimeIterator operator--(int);

    // dereference operator
	unsigned operator*() const;
};

// if we have == then we should have !=
bool operator==(const PrimeIterator& lhs, const PrimeIterator& rhs);
bool operator!=(const PrimeIterator& lhs, const PrimeIterator& rhs);