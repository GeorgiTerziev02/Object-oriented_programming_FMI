#include <iostream>
#include <fstream>
#include <sstream>

namespace Constants {
	constexpr size_t STUDENTS_MAX = 1024;
	constexpr size_t NAME_MAX_LENGTH = 16;
	constexpr size_t BUFFER_MAX_SIZE = NAME_MAX_LENGTH * 4;
}

enum class HairColor {
	BROWN = 0,
	BLACK = 1,
	BLONDE = 2,
	RED = 3,
	WHITE = 4
};

struct Student {
	double averageGrade;
	int facultyNumber;
	HairColor hairColor;
	char firstName[Constants::NAME_MAX_LENGTH + 1];
	char lastName[Constants::NAME_MAX_LENGTH + 1];
};

void saveStudentToFile(const Student& student, std::ofstream& out) {
	out << student.firstName << ";" << student.lastName << ";"
		<< student.facultyNumber << ";"
	    << static_cast<int>(student.hairColor) << ";"
		<< student.averageGrade << "\n";
}

Student readStudentFromFile(std::ifstream& in) {
	Student student;
	char buffer[Constants::NAME_MAX_LENGTH * 4];
	in.getline(buffer,  Constants::BUFFER_MAX_SIZE + 1);
	std::stringstream str(buffer);
	str.getline(student.firstName, Constants::NAME_MAX_LENGTH, ';');
	str.getline(student.lastName, Constants::NAME_MAX_LENGTH, ';');

	if (str.peek() == ';')  // skip the semicolon if present
		str.ignore(1);
	str >> student.facultyNumber;

	if (str.peek() == ';')
		str.ignore(1);

	int hairColorValue;
	str >> hairColorValue;
	student.hairColor = static_cast<HairColor>(hairColorValue);

	if (str.peek() == ';') {
		str.ignore(1);
	}

	str >> student.averageGrade;
	return student;
}

void printStudent(const Student& student) {
	std::cout << "Read Student:\n";
	std::cout << "Name: " << student.firstName << " " << student.lastName << "\n";
	std::cout << "Faculty Number: " << student.facultyNumber << "\n";
	std::cout << "Uspeh: " << student.averageGrade << "\n";
}

int main() {
    Student student1 = { 5.8, 12345, HairColor::RED, "John", "Doe" };

    // Save to file
    std::ofstream outFile("students.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }
    saveStudentToFile(student1, outFile);
    outFile.close();

    // Read from file
    std::ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }

    Student student2 = readStudentFromFile(inFile);

	printStudent(student2);

    inFile.close();

    return 0;
}