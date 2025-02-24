#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "OOP.cpp";
constexpr int BUFFER_SIZE = 1024;

int main() {
	std::ifstream in(FILE_NAME);

	if (!in.is_open()) {
		std::cout << "Could not open file" << std::endl;
		return -1;
	}

	char buffer[BUFFER_SIZE];
	while (!in.eof()) {
		in.getline(buffer, BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	in.close();
}