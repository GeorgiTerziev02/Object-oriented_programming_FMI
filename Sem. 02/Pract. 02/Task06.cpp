#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;

void printSourceCode(const char fileName[]) {
	std::ifstream in(fileName);

	if (!in.is_open()) {
		return;
	}

	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	in.close();
}