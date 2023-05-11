#include "NVector.h"
#include <iostream>
namespace {
	const double EPSILON = 0.001;
}

NVector::NVector(size_t size) {
	if (size == 0) {
		size = 1;
	}

	numbers = new int[size]();
	this->size = size;
}

NVector::NVector(const NVector& other) {
	copyFrom(other);
}

NVector& NVector::operator=(const NVector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

NVector::~NVector() {
	free();
}

void NVector::copyFrom(const NVector& other) {
	numbers = new int[other.size];
	size = other.size;

	for (size_t i = 0; i < other.size; i++) {
		numbers[i] = other.numbers[i];
	}
}

void NVector::free() {
	delete[] numbers;
	numbers = nullptr;
	size = 0;
}

NVector& NVector::operator*=(const int scalar) {
	for (size_t i = 0; i < size; i++) {
		numbers[i] *= scalar;
	}

	return *this;
}

size_t NVector::operator~() const {
	return size;
}

int NVector::operator[](size_t index) const {
	if (index >= size) {
		return numbers[size - 1]; // TODO: throw exception
	}

	return numbers[index];
}

int& NVector::operator[](size_t index) {
	if (index >= size) {
		return numbers[size - 1]; // TODO: throw exception
	}

	return numbers[index];
}

std::ostream& operator<<(std::ostream& out, const NVector& nVector) {
	out << nVector.size << " ";
	for (size_t i = 0; i < nVector.size; i++) {
		out << nVector.numbers[i] << " ";
	}

	return out;
}

std::istream& operator>>(std::istream& in, NVector& nVector) {
	in >> nVector.size;
	for (size_t i = 0; i < nVector.size; i++) {
		in >> nVector.numbers[i];
	}

	return in;
}

NVector operator+(const NVector& lhs, const NVector& rhs) {
	if (lhs.size != rhs.size) {
		return NVector(1);
	}

	NVector result(lhs);
	for (size_t i = 0; i < lhs.size; i++) {
		result.numbers[i] += rhs.numbers[i];
	}

	return result;
}

NVector operator-(const NVector& lhs, const NVector& rhs) {
	if (lhs.size != rhs.size) {
		return NVector(1);
	}

	NVector result(lhs);
	for (size_t i = 0; i < lhs.size; i++) {
		result.numbers[i] -= rhs.numbers[i];
	}

	return result;
}

// parallel
bool operator||(const NVector& lhs, const NVector& rhs) {
	if (~lhs != ~rhs) {
		return false;
	}
	
	for (int i = 0; i < ~lhs - 1; i++) {
		if (lhs[i] * rhs[i + 1] != lhs[i + 1] * rhs[i]) {
			return false;
		}
	}
	
	return true;
}

// perpendicular
bool operator|=(const NVector& lhs, const NVector& rhs) {
	int result = 0;
	for (size_t i = 0; i < ~lhs; i++) {
		result += (lhs[i] * rhs[i]);
	}

	return result == 0;
}
