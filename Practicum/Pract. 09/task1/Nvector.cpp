#include "NVector.h"
#include <cmath>
#include <stdexcept>

void NVector::copyDynamic(const NVector& other) {
	dim = other.dim;
	data = new double[dim];
	for (size_t i = 0; i < dim; i++)
		data[i] = other.data[i];
}

void NVector::freeDynamic() {
	delete[] data;
	data = nullptr;
	dim = 0;
}

NVector::NVector(size_t dimension) : dim(dimension) {
	data = new double[dim] {};
}

NVector::NVector(const NVector& other) {
	copyDynamic(other);
}

NVector& NVector::operator=(const NVector& other) {
	if (this != &other) {
		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}

NVector::~NVector() {
	freeDynamic();
}

double NVector::getLength() const {
	double sum = 0;
	for (size_t i = 0; i < dim; i++)
		sum += data[i] * data[i];
	return std::sqrt(sum);
}

double& NVector::at(size_t index) {
	if (index >= dim)
		throw std::out_of_range("Index out of range");
	return data[index];
}

const double& NVector::at(size_t index) const {
	if (index >= dim)
		throw std::out_of_range("Index out of range");
	return data[index];
}

size_t NVector::getDimension() const {
	return dim;
}

NVector NVector::operator+(const NVector& other) const {
	if (dim != other.dim)
		throw std::invalid_argument("Vectors must be same dimension");

	NVector result(dim);
	for (size_t i = 0; i < dim; i++)
		result.data[i] = data[i] + other.data[i];
	return result;
}

NVector NVector::operator-(const NVector& other) const {
	if (dim != other.dim)
		throw std::invalid_argument("Vectors must be same dimension");

	NVector result(dim);
	for (size_t i = 0; i < dim; i++)
		result.data[i] = data[i] - other.data[i];
	return result;
}

NVector NVector::operator*(double scalar) const {
	NVector result(dim);
	for (size_t i = 0; i < dim; i++)
		result.data[i] = data[i] * scalar;
	return result;
}

double& NVector::operator[](size_t index) {
	return at(index);
}

const double& NVector::operator[](size_t index) const {
	return at(index);
}

std::istream& operator>>(std::istream& is, NVector& vec) {
	for (size_t i = 0; i < vec.dim; i++)
		is >> vec.data[i];
	return is;
}

std::ostream& operator<<(std::ostream& os, const NVector& vec) {
	for (size_t i = 0; i < vec.dim; i++) {
		os << vec.data[i];
		if (i < vec.dim - 1)
			os << ' ';
	}
	return os;
}
