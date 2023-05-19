#include <iostream>
#include <cmath>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0) {}

ComplexNumber::ComplexNumber(double realPart, double imaginaryPart)
{
	setRealPart(realPart);
	setImaginaryPart(imaginaryPart);
}

void ComplexNumber::setRealPart(double realPart)
{
	this->realPart = realPart;
}

void ComplexNumber::setImaginaryPart(double imaginaryPart)
{
	this->imaginaryPart = imaginaryPart;
}

double ComplexNumber::getRealPart() const
{
	return realPart;
}

double ComplexNumber::getImaginaryPart() const
{
	return imaginaryPart;
}

bool ComplexNumber::isEqual(const ComplexNumber& other) const
{
	return other.getRealPart() == realPart && other.getImaginaryPart() == imaginaryPart;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& other) const
{
	return ComplexNumber(other.getRealPart() + realPart, other.getImaginaryPart() + imaginaryPart);
}

ComplexNumber ComplexNumber::substract(const ComplexNumber& other) const
{
	return ComplexNumber(other.getRealPart() + realPart, other.getImaginaryPart() + imaginaryPart);
}

void ComplexNumber::conjugate()
{
	imaginaryPart = -imaginaryPart;
}

ComplexNumber ComplexNumber::getConjucated() const
{
	return ComplexNumber(realPart, -imaginaryPart);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const
{
	return ComplexNumber(other.getRealPart() * realPart - other.getImaginaryPart() * imaginaryPart,
						 other.getImaginaryPart() * realPart + other.getRealPart() * imaginaryPart);
}

void ComplexNumber::print() const
{
	if (imaginaryPart > 0)
		std::cout << realPart << " + " << imaginaryPart << "i" << std::endl;

	if (imaginaryPart < 0)
		std::cout << realPart << " - " << abs(imaginaryPart) << "i" << std::endl;

	if (imaginaryPart == 0)
		std::cout << realPart << std::endl;
}
