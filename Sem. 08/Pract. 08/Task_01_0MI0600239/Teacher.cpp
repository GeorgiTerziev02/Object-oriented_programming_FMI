#include "Teacher.h"
#pragma warning (disable : 4996)

void Teacher::free()
{
	
	delete[] name;
	name = nullptr;
	
}

void Teacher::copyFrom(const Teacher& other)
{
	this->name = new char[strlen(other.name) + 1];
	std::strcpy(this->name, other.name);
}

Teacher::Teacher()
{
	name = new char[1];
	name[0] = '\0';
}

Teacher::Teacher(const Teacher& other)
{
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
}

void Teacher::setName(const char* name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}

	
	this->name = new char[strlen(name) + 1];
	std::strcpy(this->name, name);
	

}