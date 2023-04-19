#include "Teacher.h"
#include "Util.h"
#include <iostream>

void Teacher::free() {

	delete[] name;
	name = nullptr;
}

void Teacher::copyFrom(const Teacher& other) {

	Util::copyDynamicCharArray(this->name, other.name);
}

Teacher::Teacher(const char* name) {
	setName(name);
}

Teacher::Teacher(const Teacher& other) {
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Teacher::~Teacher() {
	free();
}

const char* Teacher::getName() const {
	return this->name;
}

void Teacher::setName(const char* name) {
	
	if (!name) {
		return;
	}
	delete[] this->name;
	Util::copyDynamicCharArray(this->name, name);
}