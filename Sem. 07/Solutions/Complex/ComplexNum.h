#pragma once
#include <iostream>

class ComplexNum
{
private:
	double real;
	double imaginary;
public:
	ComplexNum();
	ComplexNum(double real, double imaginary);
	
	ComplexNum(const ComplexNum& other) = default;
	ComplexNum& operator=(const ComplexNum& other) = default;
	~ComplexNum() = default;
	
	ComplexNum getConjugated() const;

	ComplexNum& operator+=(const ComplexNum& other);
	ComplexNum& operator-=(const ComplexNum& other);
	ComplexNum& operator*=(const ComplexNum& other);
	ComplexNum& operator/=(const ComplexNum& other);

	friend ComplexNum operator+(const ComplexNum& lhs, const ComplexNum& rhs);
	friend ComplexNum operator-(const ComplexNum& lhs, const ComplexNum& rhs);
	friend ComplexNum operator*(const ComplexNum& lhs, const ComplexNum& rhs) ;
	friend ComplexNum operator/(const ComplexNum& lhs, const ComplexNum& rhs);

	friend std::ostream& operator<<(std::ostream& os, const ComplexNum& complexNum);
	friend std::istream& operator>>(std::istream& is, ComplexNum& complexNum);
};
