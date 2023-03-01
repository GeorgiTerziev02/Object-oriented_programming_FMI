#include <iostream>
#include <fstream>
#include "constants.h"

void ifstreamPositioning() {
	std::ifstream in(FILE_NAME);
	char c;
	in >> c;
	std::cout << c << std::endl;
	in.seekg(-2, std::ios::end);
	std::cout << in.tellg() << std::endl;
	in >> c;
	std::cout << c << std::endl;
}

void ofstreamPositioning() {
	std::ofstream out(FILE_NAME, std::ios::_Nocreate);
	out.seekp(-5, std::ios::end);
	out << 'i';
}