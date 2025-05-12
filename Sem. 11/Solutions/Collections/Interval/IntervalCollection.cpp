#include "IntervalCollection.h"
#include <iostream>

IntervalCollection::IntervalCollection(int start, int end) {
	if (end < start) {
		std::swap(start, end);
	}

	this->start = start;
	this->end = end;

	// TODO: memory leak here!!!!
	data = new int[end - start + 1] {0};
}


unsigned IntervalCollection::intervalLength() const {
	return end - start + 1;
}

void IntervalCollection::add(int elem) {
	if (elem < start || elem > end) {
		return;
	}

	++data[elem - start];
}

void IntervalCollection::remove(int elem) {
	if (elem < start || elem > end) {
		return;
	}

	int index = elem - start;

	if (data[index] == 0) {
		return;
	}

	--data[index];
}

size_t IntervalCollection::count(int elem) const {
	if (elem < start || elem > end) {
		return 0;
	}

	return data[elem - start];
}

bool IntervalCollection::contains(int elem) const {
	return count(elem) > 0;
}