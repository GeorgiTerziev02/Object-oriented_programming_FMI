#include <iostream>

struct ComplexNumber {
	double real;
	double imaginary;
};

ComplexNumber addComplexNumbers(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return {
        lhs.real + rhs.real,
        lhs.imaginary + rhs.imaginary
    };
}

void printComplexNumber(const ComplexNumber& complex) {
	std::cout << complex.real << " " << complex.imaginary << "\n";
}

int main()
{
	ComplexNumber cn1 = { 3, 4 };
	ComplexNumber cn2 = { -10, 12 };
	ComplexNumber sum = addComplexNumbers(cn1, cn2);

	printComplexNumber(sum);
}