#include <iostream>
#include <fstream>

#pragma warning(disable: 4996)

namespace Constants {
	constexpr char FILE_NAME[] = "student.bin";
}

namespace HelperFunctions {
	void readDynamicCharArrayFromBinaryFile(std::ifstream& in, char*& str) {
		size_t nameLength;
		in.read((char*)&nameLength, sizeof(nameLength));
		str = new char[nameLength + 1];
		in.read((char*)str, nameLength);
		str[nameLength] = '\0';
	}

	void writeDynamicCharArrayToBinaryFile(std::ofstream& out, const char* str) {
		size_t nameLength = strlen(str);
		out.write((const char*)&nameLength, sizeof(nameLength));
		out.write((const char*)str, nameLength);
	}
}

struct Student {
	char* name;
	char* university;
	int age;
};

void writeStudentToBinaryFile(std::ofstream& out, const Student& st) {
	HelperFunctions::writeDynamicCharArrayToBinaryFile(out, st.name);
	HelperFunctions::writeDynamicCharArrayToBinaryFile(out, st.university);
	out.write((const char*)&st.age, sizeof(st.age));
}

void readStudentFromBinaryFile(std::ifstream& in, Student& st) {
	HelperFunctions::readDynamicCharArrayFromBinaryFile(in, st.name);
	HelperFunctions::readDynamicCharArrayFromBinaryFile(in, st.university);
	in.read((char*)&st.age, sizeof(st.age));
}

int main() {
	{
		Student st;
		st.name = new char[5];
		strcpy(st.name, "Ivan");
		st.university = new char[5];
		strcpy(st.university, "FMI");
		st.age = 20;

		std::ofstream out(Constants::FILE_NAME, std::ios::binary);
		writeStudentToBinaryFile(out, st);
		out.close();

		delete[] st.name;
		delete[] st.university;
	}

	{
		Student st;
		std::ifstream in(Constants::FILE_NAME, std::ios::binary);
		readStudentFromBinaryFile(in, st);
		in.close();

		std::cout << st.name << " " << st.university << " " << st.age;

		delete[] st.name;
		delete[] st.university;
	}
}