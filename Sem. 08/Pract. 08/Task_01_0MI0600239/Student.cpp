#include "Student.h"
#pragma warning (disable : 4996)

void Student::free()
{
	delete[] name;
	name = nullptr;
}

void Student::copyFrom(const Student& other)
{
	name = new char[strlen(other.name)+ 1];
	std::strcpy(this->name, other.name);

	fn = other.getFn();

	for (int i = 0; i < other.countGrades; i++) {
		grades[i] = other.grades[i];
	}

	countGrades = other.getCountGrades();
}

void Student::setName(const char* name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}

	this->name = new char[strlen(name) + 1];
	std::strcpy(this->name, name);

}

void Student::setFn(unsigned fn) {
	this->fn = fn;
}

unsigned Student::getFn() const {
	return fn;
}

double Student::getGradesSum() const
{
	double result=0;
	for (int i = 0; i < countGrades; i++) {
		result += grades[i].getValue();
	}
	return result;
}

void Student::addGrade(const Grade& grade) {
	if (countGrades == 7) {
		return;
	}
	grades[countGrades] = grade;
	countGrades++;
}

Student::Student()
{
	name = new char[1];
	name[0] = '\0';
	fn = 0;
	countGrades = 0;
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

double Student::getTaskGrade(const char* task) const
{
	for (int i = 0; i < countGrades; i++) {
		if (strcmp(grades[i].getTask(), task) == 0) {
			return grades[i].getValue();
		}
	}
}

const Grade* Student::getGrades() const
{
	return grades;
}

int Student::getCountGrades() const
{
	return countGrades;
}

const char* Student::getName() const
{
	return name;
}

double Student::getTeacherGrade(const char* teacher) const {

	for (int i = 0; i < countGrades; i++) {
		if (strcmp(grades[i].getTeacher(), teacher) == 0) {
			return grades[i].getValue();
		}
	}
}
