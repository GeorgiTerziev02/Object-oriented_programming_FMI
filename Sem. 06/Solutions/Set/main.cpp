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

	// 	Set s;

	// s.addNumber(5);
	// s.addNumber(8);
	// s.addNumber(6);
	// s.addNumber(7);

	// Set s2;
	// s2.addNumber(1);
	// s2.addNumber(0);
	// s2.addNumber(5);

	// Set s3 = s.intersect(s2);
	// s3.print();
}