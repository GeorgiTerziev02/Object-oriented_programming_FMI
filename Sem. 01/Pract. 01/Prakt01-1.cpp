#include <iostream>

int f1(const int n, const int m) {
	return m < n ? m : n;
}

int f2(const int* n, const int* m) {
	return *m < *n ? *m : *n;
}

int f3(const int& n, const int& m) {
	return m < n ? m : n;
}

int main() {
	int a, b;
	std::cin >> a >> b;

	std::cout << f1(a, b) << std::endl;
	std::cout << f2(&a, &b) << std::endl;
	std::cout << f3(a, b) << std::endl;

	return 0;
}