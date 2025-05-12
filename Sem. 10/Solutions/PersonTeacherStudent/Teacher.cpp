#include "Teacher.h"
#include <cstring>
#include <utility>

#pragma warning(disable : 4996)

void Teacher::copySubjects(char** subjects, size_t subjectsCount) {
	this->subjectsCount = subjectsCount;
	this->subjects = new char* [subjectsCount];
	for (size_t i = 0; i < subjectsCount; i++) {
		this->subjects[i] = new char[strlen(subjects[i])];
		strcpy(this->subjects[i], subjects[i]);
	}
}

Teacher::Teacher(const char* name, int age, char** subjects, size_t subjectsCount)
	: Person(name, age)
{
	copySubjects(subjects, subjectsCount);
}

Teacher::Teacher(const Teacher& other) : Person(other) {
    copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other) {
	if (this != &other) {
		Person::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Teacher::Teacher(Teacher&& other) noexcept : Person(std::move(other)) {
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other) noexcept {
	if (this != &other) {
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Teacher::~Teacher() {
	free();
}

void Teacher::free() {
	for (size_t i = 0; i < subjectsCount; i++) {
		delete[] subjects[i];
	}
	delete[] subjects;
}

void Teacher::copyFrom(const Teacher& other) {
	copySubjects(other.subjects, other.subjectsCount);
}

void Teacher::moveFrom(Teacher&& other) {
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;

	other.subjects = nullptr;
	other.subjectsCount = 0;
}
