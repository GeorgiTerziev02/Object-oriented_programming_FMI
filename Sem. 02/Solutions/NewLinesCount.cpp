#include <iostream>
#include <fstream>

namespace Constants {
    constexpr char FILE_NAME[] = "test.txt";
}

int getCharCountFromFile(std::ifstream& ifs, char ch) {
	if (!ifs.is_open()) {
       		return -1;
    	}

	int count = 0;

	while (true) {
		char current = ifs.get();
		if (ifs.eof()) {
			break;
        	}

		if (current == ch) {
			count++;
        	}
	}

	return count;
}

int getLinesCount(const char* fileName) {
	std::ifstream myFile(fileName);

	if (!myFile.is_open()) {
		return -1;
    	}

	return getCharCountFromFile(myFile, '\n') + 1;
}

int main() {
	std::cout << getLinesCount(Constants::FILE_NAME) << std::endl;
}
