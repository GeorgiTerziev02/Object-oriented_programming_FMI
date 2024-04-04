#pragma once

#include <iostream>

typedef unsigned char byte;
constexpr size_t min_nums_max = 1;

byte getMask(size_t posInBucket);

class MultiSet {
	byte* _data = nullptr;
	size_t _dataSize = 0;
	size_t _maxNumsCount = 0;

	void freeData();

	void copyFrom(const MultiSet& other);

	friend MultiSet getUnion(const MultiSet& set1, const MultiSet& set2);

	friend MultiSet getIntersection(const MultiSet& set1, const MultiSet& set2);

public:
	bool setOccurrences(size_t num, size_t count);

	MultiSet();

	MultiSet(size_t n);

	MultiSet(const MultiSet& other);

	MultiSet& operator=(const MultiSet& other);

	~MultiSet();

	bool addNum(size_t num);

	bool removeNum(size_t num);

	size_t nOccurrences(size_t num) const;

	void print(std::ostream& os) const;
};

MultiSet getUnion(const MultiSet& set1, const MultiSet& set2);

MultiSet getIntersection(const MultiSet& set1, const MultiSet& set2);