#include <iostream>

constexpr unsigned MAX_FIBONACCI = 5;

int fibonacci(unsigned number) {
	static unsigned cache[MAX_FIBONACCI] = { 1, 1 };
	if (number >= MAX_FIBONACCI) {
		throw std::out_of_range("Number too big!");
	}
	if (cache[number] == 0) {
		cache[number] = fibonacci(number - 1) + fibonacci(number - 2);
	}

	return cache[number];
}

const int& swap(int a, int b) {
	static unsigned swaps = 0;
	int temp = a;
	a = b;
	b = temp;

	return swaps;
}

int nextFibonacci() {
	static unsigned previous = 0;
	static unsigned current = 1;

	int temp = current;
	current = previous + current;
	previous = temp;
	return temp;
}

int idGenerator() {
    static int id = 0;
    return id++;
}

int main() {
	std::cout << nextFibonacci() << std::endl;
	std::cout << nextFibonacci() << std::endl;
	std::cout << nextFibonacci() << std::endl;
	std::cout << nextFibonacci() << std::endl;
	std::cout << nextFibonacci() << std::endl;

	std::cout << fibonacci(0) << std::endl;
	std::cout << fibonacci(1) << std::endl;
	std::cout << fibonacci(2) << std::endl;
	std::cout << fibonacci(3) << std::endl;
	std::cout << fibonacci(4) << std::endl;
	std::cout << fibonacci(5) << std::endl;
}