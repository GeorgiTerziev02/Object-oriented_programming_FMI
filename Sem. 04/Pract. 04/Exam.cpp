#include "Exam.h"
#include <fstream>

Exam::Exam() {
}

Exam::Exam(const Task* tasks, unsigned minPoints) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		this->tasks[i].setName(tasks[i].getName());
		this->tasks[i].setDescription(tasks[i].getDescription());
		this->tasks[i].setPoints(tasks[i].getPoints());
	}
	this->minPoints = minPoints;
}

void Exam::setPoints(unsigned minPoints) {
	this->minPoints = minPoints;
}

void Exam::changeMin(const unsigned minPoints) {
	this->minPoints = minPoints;
}

void Exam::writeToFile(const char* filename) const {

	std::ofstream ofs(filename, std::ios::out | std::ios::binary | std::ios::trunc);

	if (!ofs.is_open()) {
		std::cout << "Error";
		return;
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		unsigned nameLen = strlen(tasks[i].getName());
		ofs.write((const char*)&nameLen, sizeof(nameLen));

		ofs.write((const char*)tasks[i].getName(), nameLen);

		unsigned descriptionLen = strlen(tasks[i].getDescription());
		ofs.write((const char*)&descriptionLen, sizeof(descriptionLen));

		ofs.write((const char*)tasks[i].getDescription(), descriptionLen);

		int x = (tasks[i].getPoints());
		ofs.write((const char*)&x, sizeof(unsigned));
	}
	ofs.write((const char*)&minPoints, sizeof(unsigned));

	ofs.close();
}

void Exam::readFromFile(const char* filename) {
	std::ifstream ifs(filename, std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		std::cout << "Error";
		return;
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		unsigned nameLen;
		ifs.read((char*)&nameLen, sizeof(nameLen));

		const char* name = tasks[i].getName();
		this->tasks[i].setNameFromFile(ifs, nameLen);

		unsigned descriptionLen;
		ifs.read((char*)&descriptionLen, sizeof(descriptionLen));

		this->tasks[i].setDescriptionFromFile(ifs, descriptionLen);

		unsigned points;
		ifs.read((char*)&points, sizeof(unsigned));
		this->tasks[i].setPoints(points);
	}
	unsigned minP;
	ifs.read((char*)&minP, sizeof(unsigned));
	this->minPoints = minP;

	ifs.close();
}

unsigned Exam::getMax() {
	unsigned maxPoints = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		maxPoints += tasks[i].getPoints();
	}
	return maxPoints;
}

void Exam::print() {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		tasks[i].print();
	}
	std::cout << minPoints << std::endl;
}