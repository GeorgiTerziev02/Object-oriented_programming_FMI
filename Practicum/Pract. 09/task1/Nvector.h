#pragma once
#include <iostream>

class NVector {
public:
	NVector(size_t dimension);
	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();

	double getLength() const;
	double& at(size_t index);
	const double& at(size_t index) const;

	size_t getDimension() const;

	NVector operator+(const NVector& other) const;
	NVector operator-(const NVector& other) const;
	NVector operator*(double scalar) const;

	double& operator[](size_t index);
	const double& operator[](size_t index) const;

	friend std::istream& operator>>(std::istream& is, NVector& vec);
	friend std::ostream& operator<<(std::ostream& os, const NVector& vec);

private:
	double* data = nullptr;
	size_t dim;

	void copyDynamic(const NVector& other);
	void freeDynamic();
};
