#include "Singleton.h"
#include <iostream>

int main() {
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();

	// Error: trying CC is deleted
	// Singleton s3 = Singleton::getInstance();
	std::cout << (&s1 == &s2); // true
	
	s1.print();
	std::cout << (s1.getDummy() == s2.getDummy());
}