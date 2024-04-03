#pragma once

constexpr size_t capacity = 1000; // example capacity to cover wierd transition functions where we can't predict anything

class NumberSeries {
private:
	int initialValue = 0;
	int (*transitionFunction)(int) = nullptr;
	int* generatedNumbers = nullptr;
	size_t generatedNumbersCount = 0;

	void copyGeneratedNumbers(const int* newGeneratedNumbers, size_t newGeneratedNumbersCount);

	void copyFrom(const NumberSeries& other);
	void free();

	void resize(size_t size);
	void generateNumbers(size_t finalIndex);

public:
	NumberSeries(int initialValue, int (*transitionFunction)(int));

	NumberSeries() = default;
	NumberSeries(const NumberSeries& other);
	NumberSeries& operator=(const NumberSeries& other);
	~NumberSeries();

	int getNumberAtIndex(size_t index);
	bool isInSeries(int number);

	void setInitialValue(int newValue);
	void setNewTransitionFunction(int (*newFunction)(int));
};

