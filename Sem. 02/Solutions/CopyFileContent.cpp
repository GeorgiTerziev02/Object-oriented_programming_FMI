#include <fstream>
#include <iostream>

constexpr char FILE_NAME[] = "OOP.cpp";
constexpr char COPY_NAME[] = "CopyOfOOP.cpp";
constexpr int BUFFER_SIZE = 1024;

int main() {
	std::ifstream in(FILE_NAME);
	if (!in.is_open()) {
		std::cout << "Could not open file to read" << std::endl;
		return -1;
	}

	std::ofstream out(COPY_NAME);
	if (!out.is_open()) {
		std::cout << "Could not open file to write" << std::endl;
		in.close(); // !!!
		return -1;
	}

	char buffer[BUFFER_SIZE];
	while (!in.eof()) {
		in.getline(buffer, BUFFER_SIZE);
		out << buffer << std::endl;
	}

	in.close();
	out.close();
}
