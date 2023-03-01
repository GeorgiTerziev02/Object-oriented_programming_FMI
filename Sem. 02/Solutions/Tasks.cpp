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

size_t getFileSize(std::ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

size_t getRowsCount(std::ifstream& in) {
	size_t counter = 0;
	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE, '\n');
		counter++;
	}

	// might be a good idea to return the pointer to the beginning/previous position
	return counter;
}

int main() {
	std::ifstream in(FILE_NAME);
	if (!in.is_open()) {
		std::cout << INVALID_FILE_ERR_MSG;
		return;
	}

	std::cout << getFileSize(in) << std::endl;
	std::cout << getRowsCount(in) << std::endl;

	in.close();
}