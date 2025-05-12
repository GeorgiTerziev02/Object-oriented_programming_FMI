#pragma once

#include "PureNumbersCollection.h"

class SortedCollection : public PureNumbersCollection {
private:
	// returns the leftmost index
	int lowerBound(int) const;

	// returns the rightmost index
	int upperBound(int) const;
public:
	void add(int) override;
	void remove(int) override;
	size_t count(int) const override;
	bool contains(int) const override;
};

