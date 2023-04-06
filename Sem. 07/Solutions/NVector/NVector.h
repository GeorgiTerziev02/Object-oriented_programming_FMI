#pragma once
#include <iostream>

class NVector {
private:
	int* numbers;
	size_t size;

public:
	NVector(size_t size);
	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();

	NVector& operator*=(const int scalar);
	size_t operator~() const;

	int operator[](size_t index) const;
	int& operator[](size_t index);


	friend std::ostream& operator<<(std::ostream&, const NVector& nVector);
	friend std::istream& operator>>(std::istream&, NVector& nVector); 
	friend NVector operator+(const NVector& lhs, const NVector& rhs);
	friend NVector operator-(const NVector& lhs, const NVector& rhs);
	friend bool operator||(const NVector& lhs, const NVector& rhs);

private:
	void copyFrom(const NVector& other);
	void free();
};

std::ostream& operator<<(std::ostream&, const NVector& nVector);
std::istream& operator>>(std::istream&, NVector& nVector);

NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator-(const NVector& lhs, const NVector& rhs);

// parallel
bool operator||(const NVector& lhs, const NVector& rhs);

// perpendicular
bool operator|=(const NVector& lhs, const NVector& rhs);