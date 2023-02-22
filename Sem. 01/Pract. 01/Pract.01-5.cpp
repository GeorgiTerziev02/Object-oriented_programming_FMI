#include <iostream>

struct ComplexNum {
	int a;
	int b;
};

ComplexNum sum(const ComplexNum& n1, const ComplexNum& n2) {
	int sumA = n1.a + n2.a;
	int sumB = n1.b + n2.b;
	ComplexNum newNum = { sumA, sumB };
	return newNum;
}

void print(const ComplexNum& num) {
	std::cout << num.a << " + " << num.b << " * i";
}

int main() {
	ComplexNum n1, n2;
	std::cout << "real part: ";
	std::cin >> n1.a;
	std::cout << "imaginary part: ";
	std::cin >> n1.b;

	std::cout << "real part: ";
	std::cin >> n2.a;
	std::cout << "imaginary part: ";
	std::cin >> n2.b;

	std::cout << std::endl;

	ComplexNum newNum = sum(n1, n2);
	print(newNum);

	return 0;
}
