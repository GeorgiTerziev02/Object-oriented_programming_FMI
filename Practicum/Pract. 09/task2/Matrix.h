#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();
	Matrix(size_t row, size_t cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	size_t getRows() const;
	size_t getCols() const;

	Matrix& operator+=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;

	Matrix& operator-=(const Matrix& other);
	Matrix operator-(const Matrix& other) const;

	Matrix& operator*=(double scalar);
	Matrix operator*(double scalar) const;

	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);

	double* operator[](size_t index);
	const double* operator[](size_t index) const;

	Matrix operator()() const;
	operator bool() const;

	double getElementSum() const;

	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
	friend std::istream& operator>>(std::istream& is, Matrix& m);

private:
	size_t rows;
	size_t cols;
	double** data;

	void freeDynamic();
	void copyDynamic(const Matrix& other);
};

bool operator==(const Matrix& leftOther, const Matrix& rightOther);
bool operator!=(const Matrix& leftOther, const Matrix& rightOther);

bool operator<(const Matrix& leftOther, const Matrix& rightOther);
bool operator<=(const Matrix& leftOther, const Matrix& rightOther);
bool operator>(const Matrix& leftOther, const Matrix& rightOther);
bool operator>=(const Matrix& leftOther, const Matrix& rightOther);
