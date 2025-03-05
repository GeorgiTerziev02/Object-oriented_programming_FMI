#include <iostream>
#include <fstream>

namespace Constants {
	const char FILE_NAME[] = "test.txt";
	const char ERROR_MESSAGE[] = "Error";
};

void replaceCharacterInFile(const char* fileName, const char toReplace, const char replacement) {
	std::fstream file(fileName, std::ios::in | std::ios::out);

	if (!file.is_open()) {
		std::cout << Constants::ERROR_MESSAGE;
		return;
	}

	char current;
	while (true) {
		file.get(current);
		if (file.eof()) {
			break;
		}
		if (current == toReplace) {
			file.seekp(-1, std::ios::cur);
			file.put(replacement);
      file.flush();
            		// seekp also does a flush
			//file.seekp(file.tellp());
		}
	}

	file.close();
}

int main() {
	replaceCharacterInFile(Constants::FILE_NAME, 'b', 'c');
}
