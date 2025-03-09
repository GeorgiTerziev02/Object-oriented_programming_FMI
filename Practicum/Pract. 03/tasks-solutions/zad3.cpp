#include <iostream>
#include <fstream>
#include <sstream>
#define STUDENTS_MAX 1024
#define NAME_MAX_LENGTH 16

enum class HairColor {
	BROWN,
	BLACK,
	BLONDE,
	RED,
	WHITE
};

struct Student {
	double uspeh;
	int facultyNumber;
	char firstName[16];
	char lastName[16];
};

void saveStudentToFile(const Student& student, std::ofstream& out) {
	out << student.firstName << ";" << student.lastName << ";"
		<< student.facultyNumber << ";"
		<< student.uspeh << "\n";
}

Student* readStudentFromFile(std::ifstream& in) {
	Student* student = new Student;
	char buffer[NAME_MAX_LENGTH * 4];
	in.getline(buffer, NAME_MAX_LENGTH * 4 + 1);
	std::stringstream str(buffer);
	str.getline(student->firstName, NAME_MAX_LENGTH, ';');
	str.getline(student->lastName, NAME_MAX_LENGTH, ';');
	str >> student->facultyNumber;
	str >> student->uspeh;

	return student;
}

int main() {
    Student student1 = { 5.8, 12345, "John", "Doe" };

    // Save to file
    std::ofstream outFile("students.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }
    saveStudentToFile(student1, outFile);
    outFile.close();

    // Read from file
    std::ifstream inFile("students.txt");
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }

    Student* student2 = readStudentFromFile(inFile);
    inFile.close();

    // Print read student
    std::cout << "Read Student:\n";
    std::cout << "Name: " << student2->firstName << " " << student2->lastName << "\n";
    std::cout << "Faculty Number: " << student2->facultyNumber << "\n";
    std::cout << "Uspeh: " << student2->uspeh << "\n";

    return 0;
}