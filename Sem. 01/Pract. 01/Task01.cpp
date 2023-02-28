#include <iostream>

int lowerNumberByCopy(const int num1, const int num2) {
	return num1 < num2 ? num1 : num2;
}

int lowerNumberByReference(const int& num1, const int& num2) {
	return num1 < num2 ? num1 : num2;
}

int lowerNumberByPointer(const int* num1, const int* num2) {
	return *num1 < *num2 ? *num1 : *num2;
}

int main() {
	int num1, num2;
	std::cin >> num1 >> num2;

	std::cout << lowerNumberByCopy(num1, num2) << std::endl;
	std::cout << lowerNumberByReference(num1, num2) << std::endl;
	std::cout << lowerNumberByPointer(&num1, &num2) << std::endl;
}