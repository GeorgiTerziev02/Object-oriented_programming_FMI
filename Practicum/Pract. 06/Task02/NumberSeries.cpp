#include "NumberSeries.h"

void NumberSeries::expand(size_t newCapacity)
{
	if (this->capacity >= newCapacity) {
		return;
	}
	int* tmp = new int[newCapacity];
	for (size_t i = 0; i < this->size; ++i) {
		tmp[i] = this->generated[i];
	}
	this->freeGenerated();
	this->capacity = newCapacity;
	this->generated = tmp;
}

void NumberSeries::freeGenerated()
{
	if (this->generated != nullptr) {
		delete[] this->generated;
		this->generated = nullptr;
	}
}

void NumberSeries::copy(const NumberSeries& rhs)
{
	this->a_0 = rhs.a_0;
	this->_f = rhs._f;
	this->size = rhs.size;

	this->capacity = rhs.capacity;
	this->generated = new int[this->capacity];

	for (size_t i = 0; i < this->size; ++i) {
		this->generated[i] = rhs.generated[i];
	}
}

void NumberSeries::restartGenerated()
{
	this->freeGenerated();
	this->capacity = 1;
	this->generated = new int[this->capacity];
	this->generated[0] = a_0;
	this->size = 1;
}

void NumberSeries::generateNext()
{
	if (this->size >= this->capacity) {
		this->expand(this->capacity * 2);
	}
	this->generated[this->size] = this->_f(this->generated[this->size - 1]);
	++this->size;
}

NumberSeries::NumberSeries(int start, TransitionFunction f) : a_0(start), _f(f)
{
	this->restartGenerated();
}

NumberSeries::NumberSeries(const NumberSeries& rhs)
{
	this->copy(rhs);
}

NumberSeries& NumberSeries::operator=(const NumberSeries& rhs)
{
	if (this != &rhs) {
		freeGenerated();
		this->copy(rhs);
	}
	return *this;
}

NumberSeries::~NumberSeries()
{
	this->freeGenerated();
	this->size = 0;
	this->capacity = 0;
}

int NumberSeries::generateNumber(size_t at)
{
	while (this->size <= at) {
		this->generateNext();
	}
	return this->generated[at];
}

bool NumberSeries::isInSerie(int elem) const
{
	for (size_t i = 0; i < this->size; ++i) {
		if (this->generated[i] == elem) {
			return true;
		}
	}
	return false;
}

void NumberSeries::setFirst(int first)
{
	this->a_0 = first;
	this->restartGenerated();
}

void NumberSeries::setTransitionFunction(TransitionFunction f)
{
	this->_f = f;
	this->restartGenerated();
}
