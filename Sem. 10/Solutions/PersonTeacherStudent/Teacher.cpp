#include "Teacher.h"
#include <cstring>
#include <utility>

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount)
	: Person(name, age)
{
	// todo:
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
	subjectsCount = other.subjectsCount;
	subjects = new char* [subjectsCount];
	for (size_t i = 0; i < subjectsCount; i++) {
		subjects[i] = new char[strlen(other.subjects[i])];
		strcpy(subjects[i], other.subjects[i]);
	}
}

void Teacher::moveFrom(Teacher&& other) {
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;

	other.subjects = nullptr;
	other.subjectsCount = 0;
}
