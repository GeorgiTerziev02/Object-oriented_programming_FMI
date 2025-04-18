#pragma once

class Matrix
{

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	~Matrix() noexcept;


	Matrix& operator=(const Matrix& rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);

	Matrix& operator++();
	Matrix operator++(int dummy);
	Matrix& operator--();
	Matrix operator--(int dummy);

	Matrix& operator*=(int num);
	
	int* operator[](unsigned index);
	const int* operator[](unsigned index) const;

	Matrix operator()();

	operator bool() const;

	int getRows() const { return this->rows; }
	int getCols() const { return this->cols; }

	void print() const;

private:
	int** matrix;
	int rows;
	int cols;

private:
	void freeDynamic();
	void copyDynamic(const Matrix& other);
};


bool operator<(const Matrix& lhs, const Matrix& rhs);
bool operator==(const Matrix& lhs, const Matrix& rhs);
bool operator<=(const Matrix& lhs, const Matrix& rhs);
bool operator>(const Matrix& lhs, const Matrix& rhs);
bool operator>=(const Matrix& lhs, const Matrix& rhs);

bool Equals(const Matrix& lhs, const Matrix& rhs);
bool operator!=(const Matrix& lhs, const Matrix& rhs);

