#include "MultiSet.h"

#include <iostream>

void MultiSet::copyNumbers(const int* newElements, size_t newElementsCount) {
	elements = new int[newElementsCount]();

	for (int i = 0; i < newElementsCount; i++) {
		elements[i] = newElements[i];
	}

	elementsCount = newElementsCount;
}

void MultiSet::copyFrom(const MultiSet& other) {
	copyNumbers(other.elements, other.elementsCount);
	maxNumber = other.maxNumber;
}

void MultiSet::free() {
	delete[] elements;
	elements = nullptr;
	maxNumber = 0;
	elementsCount = 0;
}

void MultiSet::resize(int sizeChange) {
	if (sizeChange == 0) {
		return;
	}

	int* newElements = new int[elementsCount + sizeChange]();
	int currentElementsCount = (sizeChange > 0) ? elementsCount : (elementsCount + sizeChange);
	for (int i = 0; i < currentElementsCount; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
	elementsCount += sizeChange;
}

MultiSet::MultiSet(int maxNumber) {
	this->maxNumber = maxNumber;
}

MultiSet::MultiSet(int maxNumber, int* elements, size_t elementsCount) {
	for (int i = 0; i < elementsCount; i++) {
		if (elements[i] >= maxNumber) {
			return;
		}
	}

	this->maxNumber = maxNumber;
	copyNumbers(elements, elementsCount);
}

MultiSet::MultiSet(const MultiSet& other) {
	copyFrom(other);
}

MultiSet& MultiSet::operator=(const MultiSet& other) {
	if (this != &other) {
		copyFrom(other);
		free();
	}

	return *this;
}

MultiSet::~MultiSet() {
	free();
}

int MultiSet::getMaxNumber() const {
	return maxNumber;
}

size_t MultiSet::getElementsCount() const {
	return elementsCount;
}

void MultiSet::setMaxNumber(int newMaxNumber) {
	maxNumber = newMaxNumber;
}

int MultiSet::getNumberLastPosition(int number) const {
	for (int i = elementsCount - 1; i >= 0; i--) {
		if (number == elements[i]) {
			return i;
		}
	}

	return -1;
}

size_t MultiSet::getNumberCount(int number) const {
	size_t count = 0;

	for (int i = 0; i < elementsCount; i++) {
		if (number == elements[i]) {
			count++;
		}
	}

	return count;
}

void MultiSet::printAllElements() const {
	for (int i = 0; i < elementsCount; i++) {
		std::cout << elements[i] << " ";
	}

	std::cout << std::endl;
}

void MultiSet::add(int number) {
	if (number < 0 || number >= maxNumber) {
		std::cout << "Invalid number.\n";
		return;
	}
	else if (getNumberCount(number) >= MAX_NUMBER_COUNT) {
		std::cout << "The number is element in the array " << MAX_NUMBER_COUNT << " times already.\n";
		return;
	}

	resize(1);
	elements[elementsCount - 1] = number;
}

void MultiSet::remove(int number) {
	if (number < 0 || number >= maxNumber) {
		std::cout << "Invalid number.\n";
		return;
	}
	
	int lastPosition = getNumberLastPosition(number);
	if (lastPosition == -1) {
		std::cout << "Number not among elements.\n";
		return;
	}
	else {
		for (int i = lastPosition; i < elementsCount - 1; i++) {
			elements[i] = elements[i + 1];
		}

		resize(-1);
	}
}

MultiSet intersect(const MultiSet& set1, const MultiSet& set2) {
	int resultMaxNumber = std::min(set1.getMaxNumber(), set2.getMaxNumber());
	int* countOfNumber = new int[resultMaxNumber]();

	for (int i = 0; i < resultMaxNumber; i++) {
		countOfNumber[i] += std::min(set1.getNumberCount(i), set2.getNumberCount(i));
	}

	MultiSet result(resultMaxNumber);

	for (int i = 0; i < resultMaxNumber; i++) {
		for (int j = 0; j < countOfNumber[i]; j++) {
			result.add(i);
		}
	}

	delete[] countOfNumber;

	return result;
}

MultiSet unite(const MultiSet& set1, const MultiSet& set2) {
	int resultMaxNumber = std::max(set1.getMaxNumber(), set2.getMaxNumber());
	int* countOfNumber = new int[resultMaxNumber]();

	for (int i = 0; i < resultMaxNumber; i++) {
		countOfNumber[i] += set1.getNumberCount(i) + set2.getNumberCount(i);

		if (countOfNumber[i] > 3) {
			countOfNumber[i] = 3;
		}
	}

	MultiSet result(resultMaxNumber);

	for (int i = 0; i < resultMaxNumber; i++) {
		for (int j = 0; j < countOfNumber[i]; j++) {
			result.add(i);
		}
	}

	delete[] countOfNumber;

	return result;
}
