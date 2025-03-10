#include <iostream>
#include <fstream>

namespace Constants {
	const size_t MAX_NAME_SIZE = 20;
	const char FILE_NAME[] = "test.txt";
}

struct Student {
	int number;
	char name[Constants::MAX_NAME_SIZE + 1];
	// 3 extra padding
};

size_t getFileSize(std::ifstream& f) {
	size_t currentPos = f.tellg();
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;
}


int main() {
	{
		Student s[] = { {155555, "12345678901234567890"}, {65, "123"}};
		

		std::ofstream out(Constants::FILE_NAME, std::ios::binary);
		if (!out.is_open()) {
			return -1;
		}

		out.write((const char*)&s, sizeof(s));

		out.close();
	}

	{
		std::ifstream in(Constants::FILE_NAME, std::ios::binary);
		if (!in.is_open()) {
			return -1;
		}

		size_t fSize = getFileSize(in);
		Student* s = new Student[fSize / sizeof(Student)];

		in.read((char*)s, fSize);

		std::cout << s[0].number << "\n" << s[0].name;

		in.close();
	}


}