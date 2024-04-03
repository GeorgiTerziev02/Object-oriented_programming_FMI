#pragma once

constexpr size_t MAX_NUMBER_COUNT = 3;

class MultiSet {
private:
	int maxNumber = 0;
	int* elements = nullptr;
	size_t elementsCount = 0;

	void copyNumbers(const int* newElements, size_t newElementsCount);

	void copyFrom(const MultiSet& other);
	void free();

	void resize(int sizeChange); // cover both adding (sizeChange > 0) and removing(sizeChange < 0)

public:
	MultiSet(int maxNumber);
	MultiSet(int maxNumber, int* elements, size_t elementsCount); // maybe needs additional validation?

	MultiSet() = default;
	MultiSet(const MultiSet& other);
	MultiSet& operator=(const MultiSet& other);
	~MultiSet();

	int getMaxNumber() const;
	size_t getElementsCount() const;

	void setMaxNumber(int newMaxNumber);

	int getNumberLastPosition(int number) const;
	size_t getNumberCount(int number) const;
	void printAllElements() const;

	void add(int number);
	void remove(int number);
};

MultiSet unite(const MultiSet& set1, const MultiSet& set2);
MultiSet intersect(const MultiSet& set1, const MultiSet& set2);
