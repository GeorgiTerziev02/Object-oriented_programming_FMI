#include <iostream>
#include <fstream>

void failExample() {
	std::cout << "Fail example" << std::endl;
	int a;
	std::cin >> a; // enter a letter
	std::cout << std::cin.fail() << std::endl; // true
	std::cout << std::cin.good() << std::endl; // false
	std::cin.clear();
	std::cout << std::cin.fail() << std::endl; // false
	std::cout << std::cin.good() << std::endl; // true
}

void badExample() {
	std::cout << "Bad example" << std::endl;
	std::ofstream out("someFileThatDoesExist.cpp", std::ios::_Nocreate);
	out.put('a');

	std::cout << out.bad() << std::endl; // true
	std::cout << out.good() << std::endl; // false
	std::cin.clear(); // bad is irrecoverable
	std::cout << out.bad() << std::endl; // true
	std::cout << out.good() << std::endl; // false
}

int main() {
	failExample();
	badExample();
}