#include <iostream>
#include <fstream>

unsigned getCharCountFromFile(std::ifstream& ifs, char ch) {
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open()) {
		return 0;
	}

	unsigned int count = 0;
	char current;
	while (true) {
		in.get(current); // current = in.get();
		if (in.eof()) {
			break;
		}

		if (current == ch) {
			count++;
		}
	}

	in.clear();
	in.seekg(currentPosition);
	return count;
}

unsigned getLinesCount(const char* fileName) {
	std::ifstream in(fileName);

	if (!in.is_open()) {
		return 0;
	}

	return getCharCountFromFile(in, '\n') + 1;
}

int main()
{
	std::cout << getLinesCount("file.txt");
}
