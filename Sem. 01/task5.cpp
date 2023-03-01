#include <iostream>

using std::cout;
using std::cin;
using std::endl;

namespace ComplexNS
{
	struct ComplexNum
	{
		double real;
		double imaginary;
	};

	ComplexNum SumComplNums(ComplexNum num1, ComplexNum num2)
	{
		ComplexNum result;
		result.real = num1.real + num2.real;
		result.imaginary = num1.imaginary + num2.imaginary;
		return result;
	}

	void GetComplexNum(ComplexNum& num)
	{
		cin >> num.real;
		cin >> num.imaginary;
	}

	void Print(const ComplexNum& num)
	{
		cout << num.real << " ";
		if (num.imaginary > 0)
		{
			cout << " + " << num.imaginary << "i";
		}
		else if (num.imaginary == 0)
		{
			cout << " ";
		}
		else
		{
			cout << num.imaginary << "i";
		}
	}
}


int main()
{
	using namespace ComplexNS;

	ComplexNum num1, num2, result;
	GetComplexNum(num1);
	GetComplexNum(num2);
	result = SumComplNums(num1, num2);

	Print(result);
}