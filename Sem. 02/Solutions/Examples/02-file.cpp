#include <iostream>
#include <fstream>
#include "constants.h"

int baseExample1() {
	{
		std::ofstream out(FILE_NAME); // create input file stream associated with test.txt
		
		if (!out.is_open()) {
			std::cout << INVALID_FILE_ERR_MSG << std::endl;
			return -1;
		}

		int a = 5, b = 7;
		out << a << " " << b; // try to remove the space

		out.close();
	}

	{
		std::ifstream in(FILE_NAME); // create input file stream associated with test.txt

		if (!in.is_open()) {
			std::cout << INVALID_FILE_ERR_MSG << std::endl;
			return -1;
		}

		int a, b;
		in >> a >> b;
		std::cout << a << b;

		in.close();
	}
}

int formattedInput() {
	{
		std::ofstream out(FILE_NAME);

		if (!out.is_open()) {
			std::cout << INVALID_FILE_ERR_MSG;
			return -1;
		}

		char test[] = "fadfasfasf fdsafsadf fsdaf";
		out << 5 << test;

		out.close();
	}

	{
		std::ifstream in(FILE_NAME);

		if (!in.is_open()) {
			std::cout << INVALID_FILE_ERR_MSG;
			return -1;
		}

		int a;
		char test[300];
		in >> a >> test;

		std::cout << a << " " << test;
	}
}

int unformattedInput() {
	{
		std::ofstream out(FILE_NAME);

		if (!out.is_open()) {
			std::cout << INVALID_FILE_ERR_MSG;
			return -1;
		}

		char test[] = "fadfasfasf fdsafsadf fsdaf";
		out.write(test, sizeof(test));

		out.close();
	}

	{
		std::ifstream in(FILE_NAME);

		if (!in.is_open()) {
			std::cout << INVALID_FILE_ERR_MSG;
			return -1;
		}

		char test[300];
		in.getline(test, 30);

		std::cout << test;
		in.close();
	}
}