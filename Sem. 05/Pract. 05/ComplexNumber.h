#pragma once
class ComplexNumber
{
public:
	ComplexNumber();
	ComplexNumber(double, double);

	void setRealPart(double);
	void setImaginaryPart(double);

	double getRealPart() const;
	double getImaginaryPart() const;

	void print() const;

	bool isEqual(const ComplexNumber&) const;
	ComplexNumber add(const ComplexNumber&) const;
	ComplexNumber substract(const ComplexNumber&) const;
	ComplexNumber multiply(const ComplexNumber&) const;
	void conjugate();
	ComplexNumber getConjucated() const;

private:
	double realPart;
	double imaginaryPart;
};

