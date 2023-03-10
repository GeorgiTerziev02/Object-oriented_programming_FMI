#include <iostream>
#include <fstream>
#include "constants.h"

int test() {
	std::ifstream file(FILE_NAME);
	//file.good();  // all operations went good
	//file.clear(); // clears all failures, sets good to true
	//file.fail();  // last operation failed
	//file.bad();   // input/output operation went bad
	//file.eof();	// reached the end of file

	return 0;
}

int failExample() {
	int a;
	std::cin >> a;
	std::cout << std::cin.fail() << std::endl; // true
	std::cout << std::cin.good() << std::endl; // false
	std::cin.clear();
	std::cout << std::cin.fail() << std::endl; // false
	std::cout << std::cin.good() << std::endl; // true

	return 0;
}