#include "Student.h"
#include <cstring>

void Student::copyName(const char* newName) {
	size_t newNameLength = strlen(newName);
	this->name = new char[newNameLength + 1];
	strcpy(this->name, newName);
}

Student::Student(int grade, const char* name) {
	this->grade = grade;
	copyName(name);
}

const char* Student::getName() const {
	return name;
}

void Student::setName(const char* newName) {
	if (strlen(newName) == 0) {
		return;
	}

	delete[] name;
	copyName(newName);
}
