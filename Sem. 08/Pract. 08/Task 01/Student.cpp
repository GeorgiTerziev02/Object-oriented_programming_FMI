#include "Student.h"
#include "Util.h"
#include <cstring>
#include <iostream>
#pragma warning (disable: 4996)


void Student::free() {

	delete[] name;
	name = nullptr;
	facultyNumber = 0;
	gradesCount = 0;
}

void Student::copyFrom(const Student& other)
{
	this->facultyNumber = other.facultyNumber;
	this->gradesCount = other.gradesCount;
	Util::copyDynamicCharArray(this->name, other.name);

	for (size_t i = 0; i < gradesCount; i++) {
		this->grades[i] = other.grades[i];
	}
}

Student::Student(const char* name, unsigned int facultyNumber):facultyNumber(facultyNumber), gradesCount(0) {
	setName(name);
}

Student::Student(const Student& other) {
	copyFrom(other);
}

Student& Student::operator=(const Student& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Student::~Student() {
	free();
}

const char* Student::getName() const {
	if (!this->name) {
		std::cout << "name is deleted!";
	}
	return this->name;
}

unsigned int Student::getFacultyNumber() const {
	return this->facultyNumber;
}

void Student::setName(const char* name) {
	if (!name || this->name == name) {
		throw "Error! Bad name!";
	}

	delete[] this->name;
	Util::copyDynamicCharArray(this->name, name);
}

void Student::setFacultyNumber(unsigned int facultyNumber) {
	this->facultyNumber = facultyNumber;
}

const size_t Student::getGradesCount() const {
	return gradesCount;
}

void Student::receiveGrade(const Grade& grade) {
	if (gradesCount == MAX_GRADES_PER_STUDENT_AMOUNT) {
		throw "Error! This student has reached max amount of grades!";
	}
	if (getGradeValueByTaskName(grade.getTask()) != 0) {
		throw "Error! This student already has a grade for this task!";
	}

	grades[gradesCount++] = grade;
}

Grade& Student::getGradeByTaskName(const char* task) {
	for (size_t i = 0; i < gradesCount; i++) {
		if (strcmp(grades[i].getTask(), task) == 0) {
			return grades[i];
		}
	}
	throw std::exception("No such grade!");
}

void Student::editGrade(const char* task, double newValue) {
	getGradeByTaskName(task).setValue(newValue);
}

const double Student::getGradeValueByTaskName(const char* task) const {
	for (size_t i = 0; i < gradesCount; i++) {
		if (strcmp(grades[i].getTask(), task) == 0) {
			return grades[i].getValue();
		}
	}
	return 0;
}