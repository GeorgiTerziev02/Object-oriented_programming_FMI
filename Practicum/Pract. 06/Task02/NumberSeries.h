#pragma once

typedef int (*TransitionFunction)(int);

class NumberSeries {
	int a_0 = 0;
	TransitionFunction _f = nullptr;


	int* generated = nullptr;
	size_t size = 1;
	size_t capacity = 1;

	void expand(size_t newCapacity);

	void freeGenerated();

	void copy(const NumberSeries& rhs);

	void restartGenerated();

	void generateNext();

public:
	NumberSeries(int start, TransitionFunction f);

	NumberSeries(const NumberSeries& rhs);

	NumberSeries& operator=(const NumberSeries& rhs);

	~NumberSeries();

	int generateNumber(size_t at);

	bool isInSerie(int elem) const;

	void setFirst(int first);

	void setTransitionFunction(TransitionFunction f);
};