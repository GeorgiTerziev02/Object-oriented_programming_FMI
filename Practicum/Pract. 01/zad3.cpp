
#include <iostream>
struct ComplexNum
{
	int real;
	int complex;
};

ComplexNum AddComlex(const ComplexNum& A, const ComplexNum& B)
{
	ComplexNum result;
	result.real = A.real + B.real;
	result.complex = A.complex + B.complex;
	return result;
}

void PrintNum(const ComplexNum& number)
{
	std::cout << number.real << "," << number.complex << std::endl;
}
int main()
{
	ComplexNum i = { 1,1 };
	ComplexNum j = { 2,2 };
	PrintNum(i);
	PrintNum(j);
	PrintNum(AddComlex(i, j));
}
