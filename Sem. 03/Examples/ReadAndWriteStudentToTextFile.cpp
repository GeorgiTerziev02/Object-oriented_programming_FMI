#include <iostream>
#include <fstream>

namespace Constants {
	const size_t MAX_NAME_SIZE = 20;
	const char FILE_NAME[] = "test.txt";
}

struct Student {
	int number;
	char name[Constants::MAX_NAME_SIZE + 1];
};

int main() {
	{
		Student s = { 5, "12345678901234567890" };

		std::ofstream out(Constants::FILE_NAME);
		if (!out.is_open()) {
			return -1;
		}

		out << s.number << '\n' << s.name;

		out.close();
	}

	{
		Student s;

		std::ifstream in(Constants::FILE_NAME);
		if (!in.is_open()) {
			return -1;
		}

		in >> s.number;
		in.ignore();
		// getline includes the terminating zero in the count
		in.getline(s.name, Constants::MAX_NAME_SIZE + 1);

		std::cout << s.number << "\n" << s.name;

		in.close();
	}
}