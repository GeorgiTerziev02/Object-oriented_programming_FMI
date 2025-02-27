#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "OOP.cpp";

int main() {
	std::ifstream in(FILE_NAME);

	if (!in.is_open()) {
		return -1;
	}

	char symbol;
	while (!in.eof()) {
		in.get(symbol);
		std::cout << symbol;
	}

    in.close();
}