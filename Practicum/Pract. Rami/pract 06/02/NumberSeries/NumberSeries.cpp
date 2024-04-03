#include "NumberSeries.h"
#include <iostream>

void NumberSeries::copyGeneratedNumbers(const int* newGeneratedNumbers, size_t newGeneratedNumbersCount) {
	generatedNumbersCount = newGeneratedNumbersCount;

	generatedNumbers = new int[generatedNumbersCount];
	for (int i = 0; i < newGeneratedNumbersCount; i++) {
		generatedNumbers[i] = newGeneratedNumbers[i];
	}
}

void NumberSeries::copyFrom(const NumberSeries& other) {
	copyGeneratedNumbers(other.generatedNumbers, other.generatedNumbersCount);
	initialValue = other.initialValue;
	transitionFunction = other.transitionFunction;
}

void NumberSeries::free() {
	delete[] generatedNumbers;
	generatedNumbers = nullptr;
	transitionFunction = nullptr;
	initialValue = 0;
	generatedNumbersCount = 0;
}

NumberSeries::NumberSeries(const NumberSeries& other) {
	copyFrom(other);
}

NumberSeries& NumberSeries::operator=(const NumberSeries& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

NumberSeries::~NumberSeries() {
	free();
}

NumberSeries::NumberSeries(int initialValue, int (*transitionFunction)(int)) {
	this->initialValue = initialValue;
	this->transitionFunction = transitionFunction;

	generatedNumbers = nullptr;
	generatedNumbersCount = 0;
}

void NumberSeries::resize(size_t size) {
	int* copyNumbers = new int[generatedNumbersCount + size]();
	for (int i = 0; i < generatedNumbersCount; i++) {
		copyNumbers[i] = generatedNumbers[i];
	}

	delete[] generatedNumbers;
	generatedNumbers = copyNumbers;
}

void NumberSeries::generateNumbers(size_t finalIndex) {
	if (finalIndex > capacity) {
		return;
	}

	resize(finalIndex - generatedNumbersCount);

	for (int i = generatedNumbersCount; i < finalIndex; i++) {
		if (i == 0) {
			generatedNumbers[i] = transitionFunction(initialValue);
		} 
		else {
			generatedNumbers[i] = transitionFunction(generatedNumbers[i - 1]);
		}
	}

	generatedNumbersCount = finalIndex;
}

int NumberSeries::getNumberAtIndex(size_t index) {
	if (index > capacity) {
		std::cout << "Number is outside of the maximum capacity.\n";
	}
	else if (index == 0) {
		return initialValue;
	}
	else if (index <= generatedNumbersCount) {
		return generatedNumbers[index - 1];
	}

	generateNumbers(index);
	return generatedNumbers[index - 1];
}

bool NumberSeries::isInSeries(int number) {
	for (int i = 0; i < generatedNumbersCount; i++) {
		if (number == generatedNumbers[i]) {
			return true;
		}
	}

	// main problem is that the transition function could be smth like a_i+1 = a_i * (-3) + 5 and hence the series is neither 
	// descending, nor ascending => we can't know for sure if the number is in the series unless we reach the full capacity.
	while (true) {
		generateNumbers(generatedNumbersCount + 1);
		if (number == generatedNumbers[generatedNumbersCount - 1]) {
			return true;
		}
		else if (generatedNumbersCount >= capacity) {
			break;
		}
	}

	return false;
}

void NumberSeries::setInitialValue(int newValue) {
	initialValue = newValue;

	free();
	generatedNumbersCount = 0;
}

void NumberSeries::setNewTransitionFunction(int (*newFunction)(int)) {
	transitionFunction = newFunction;
}
