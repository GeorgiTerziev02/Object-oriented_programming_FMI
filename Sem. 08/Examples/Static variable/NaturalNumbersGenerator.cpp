#include <iostream>

size_t naturalNumbersGenerator() {
	static size_t current = 1;
	 
	return current++;
}

int main() {
	std::cout << naturalNumbersGenerator();
	std::cout << naturalNumbersGenerator();
	std::cout << naturalNumbersGenerator();
	std::cout << naturalNumbersGenerator();
}