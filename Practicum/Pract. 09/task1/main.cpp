#include <iostream>
#include "NVector.h"

int main() {
	NVector a(3), b(3);
	std::cin >> a >> b;

	NVector sum = a + b;
	NVector diff = a - b;
	NVector scaled = a * 2.5;

	std::cout << "a + b = " << sum << '\n';
	std::cout << "a - b = " << diff << '\n';
	std::cout << "a * 2.5 = " << scaled << '\n';
	std::cout << "Length of a: " << a.getLength() << '\n';

	std::cout << "a[1] = " << a[1] << '\n';
	return 0;
}
