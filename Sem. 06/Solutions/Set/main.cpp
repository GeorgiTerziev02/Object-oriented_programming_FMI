#include "Set.h"
#include <iostream>

int main() {
	Set s;
	s.addNumber(3);
	s.addNumber(7);
	s.addNumber(8);
	s.addNumber(23);
	std::cout << s.containsNumber(8);
	s.removeNumber(8);
	std::cout << s.containsNumber(8);
	std::cout << std::endl;
	
	s.print();
	std::cout << std::endl;
	s.printBits();
}