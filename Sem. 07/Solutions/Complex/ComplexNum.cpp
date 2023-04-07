#include "ComplexNum.h"

ComplexNum::ComplexNum() {
	real = imaginary = 0;
}

ComplexNum::ComplexNum(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNum& ComplexNum::operator+=(const ComplexNum& other) {
	real += other.real;
	imaginary += other.imaginary;

	return *this;
}

ComplexNum& ComplexNum::operator-=(const ComplexNum& other) {
	real -= other.real;
	imaginary -= other.imaginary;

	return *this;
}

ComplexNum& ComplexNum::operator*=(const ComplexNum& other) {
	double oldReal = real;
	real = real * other.real - imaginary * other.imaginary;
	imaginary = oldReal * other.imaginary + imaginary * other.real;
	return *this;
}

ComplexNum& ComplexNum::operator/=(const ComplexNum& other) {
	ComplexNum conjugated = other.getConjugated(); //взимаме комплексно спрегнатата на другата дроб (b)

	ComplexNum otherCopy(other);// копираме другата (b), за да не я промяняме.

	//Умножаваме двете по комплексно спрегнатата.
	*this *= conjugated;
	otherCopy *= conjugated; //Тук трябва да остане само реална част.

	if (otherCopy.real != 0) {
		real /= otherCopy.real;
		imaginary /= otherCopy.real;
	}

	return *this;
}

ComplexNum operator+(ComplexNum& lhs, const ComplexNum& rhs) {
	ComplexNum temp(lhs);
	temp += rhs;
	return temp;
}

ComplexNum operator-(ComplexNum& lhs, const ComplexNum& rhs) {
	ComplexNum temp(lhs);
	temp -= rhs;
	return temp;
}

ComplexNum operator*(ComplexNum& lhs, const ComplexNum& rhs) {
	ComplexNum temp(lhs);
	temp *= rhs;
	return temp;
}

ComplexNum operator/(ComplexNum& lhs, const ComplexNum& rhs) {
	ComplexNum temp(lhs);
	temp /= rhs;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const ComplexNum& complexNum) {
	os << complexNum.real;
	
	if (complexNum.imaginary > 0) {
		os << "+" << complexNum.imaginary << "*i";
	} else if (complexNum.imaginary < 0) {
		os << complexNum.imaginary << "*i";
	}

	return os;
}

std::istream& operator>>(std::istream& is, ComplexNum& complexNum) {
	is >> complexNum.real >> complexNum.imaginary;
	return is;
}

ComplexNum ComplexNum::getConjugated() const {
	ComplexNum result(*this);
	result.imaginary *= -1;

	return result;
}
