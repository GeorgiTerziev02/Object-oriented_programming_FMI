#include <iostream>
#include <fstream>
#include "constants.h"

void printSourceCode(const char fileName[]) {
	std::ifstream in(fileName);

	if (!in.is_open()) {
		std::cout << INVALID_FILE_ERR_MSG;
		return;
	}

	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	in.close();
}