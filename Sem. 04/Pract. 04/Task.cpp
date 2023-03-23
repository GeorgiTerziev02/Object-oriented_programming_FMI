#include "Task.h"
#include <fstream>


#pragma warning( disable : 4996)

Task::Task() {
	name = nullptr;
	description = nullptr;
	points = 0;
}

Task::Task(const char* name, const char* description, unsigned points) {
	setName(name);
	setDescription(description);
	setPoints(points);
}

void Task::setName(const char* name) {
	if (this->name != nullptr) {
		delete[] this->name;
	}

	unsigned nameLen = 0;
	nameLen = strlen(name);

	this->name = new char[nameLen + 1];
	strcpy(this->name, name);
}

void Task::setDescription(const char* description) {
	if (this->description != nullptr) {
		delete[] this->description;
	}

	unsigned nameLen = 0;
	nameLen = strlen(description);

	this->description = new char[nameLen + 1];
	strcpy(this->description, description);
	this->description[nameLen] = '\0';
}

void Task::setNameFromFile(std::ifstream& ifs, unsigned nameLen) {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	this->name = new char[nameLen + 1];
	ifs.read(this->name, nameLen);
	this->name[nameLen] = '\0';
}

void Task::setDescriptionFromFile(std::ifstream& ifs, unsigned descriptionLen) {
	if (this->description != nullptr) {
		delete[] this->description;
	}
	this->description = new char[descriptionLen + 1];
	ifs.read((char*)this->description, descriptionLen);
	this->description[descriptionLen] = '\0';
}

void Task::setPoints(unsigned points) {
	if (points < 0) {
		points = 0;
	}
	this->points = points;
}

const char* Task::getName() const {
	return name;
}

const char* Task::getDescription() const {
	return description;
}

unsigned Task::getPoints() const {
	return points;
}

void Task::print() {
	const char* name = getName();
	unsigned nameLen = strlen(name);
	for (int i = 0; i < nameLen; i++) {
		std::cout << name[i];
	}
	std::cout << " ";

	const char* description = getDescription();
	unsigned desLen = strlen(description);
	for (int i = 0; i < desLen; i++) {
		std::cout << description[i];
	}
	std::cout << " ";
	std::cout << getPoints() << std::endl;
}

Task::~Task() {
	delete[] name;
	delete[] description;
}
