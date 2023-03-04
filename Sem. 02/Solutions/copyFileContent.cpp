#include <iostream>
#include <fstream>
#include "constants.h"

void copyFileContent(const char from[], const char to[]) {
	std::ifstream in(from);
	std::ofstream out(to);

	if (!in.is_open() || !out.is_open()) {
		std::cout << INVALID_FILE_ERR_MSG;
		return;
	}

	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		out << buffer;
	}

	in.close();
	out.close();
}