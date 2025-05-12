#pragma once

#include "../Collection.h"
#include "DynamicCollection.h"

class IntervalCollection : public DynamicCollection {
private:
	int start;
	int end;
public:
	IntervalCollection(int start, int end);
	unsigned intervalLength() const;

	void add(int) override;
	void remove(int) override;
	size_t count(int) const override;
	bool contains(int) const override;
};