#include <iostream>
#include <fstream>

constexpr int NAME_SIZE = 64;
constexpr char FILE_NAME[] = "Students.txt";

enum class Major {
	SE,
	CS,
	IS
};

struct Student {
	char name[NAME_SIZE];
	int age;
	Major major;
};

void writeStudentToStream(std::ofstream& out, const Student& st) {
	out << (int)st.major << std::endl;
	out << st.name << std::endl;
	out << st.age << std::endl;
}

void writeStudentsToFile(const char* fileName, const Student* arr, int length) {
	if (!fileName) {
		return;
	}

	std::ofstream out(fileName);
	if (!out.is_open()) {
		return;
	}

	out << length << std::endl;
	for (size_t i = 0; i < length; i++) {
		writeStudentToStream(out, arr[i]);
	}

	out.close();
}

void readStudentFromStream(std::ifstream& in, Student& st) {
	int majorInt;
	in >> majorInt;
	st.major = (Major)majorInt;
	in.ignore();
	in.getline(st.name, NAME_SIZE);
	in >> st.age;
}

Student* readStudentsFromFile(const char* fileName, size_t& length) {
	if (!fileName) {
		length = 0;
		return nullptr;
	}

	std::ifstream in(fileName);
	if (!in.is_open()) {
		length = 0;
		return nullptr;
	}

	in >> length;
	if (length == 0) {
		return nullptr;
	}

	Student* arr = new Student[length];
	for (size_t i = 0; i < length; i++) {
		readStudentFromStream(in, arr[i]);
	}

	in.close();
	return arr;
}

void printStudent(const Student& st) {
	std::cout << st.name << " " << st.age << " " << (int)st.major << std::endl;
}

int main() {
	constexpr int LENGTH = 2;
	Student arr[LENGTH] = { 
		{ "Ivan 123", 30, Major::CS }, 
		{ "Pe6o 456", 20, Major::SE } 
	};

	writeStudentsToFile(FILE_NAME, arr, LENGTH);

	size_t length;
	Student* result = readStudentsFromFile(FILE_NAME, length);

	for (size_t i = 0; i < length; i++) {
		printStudent(result[i]);
	}

	delete[] result;
};