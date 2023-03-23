#pragma once

#include "Task.h"

const unsigned ARRAY_SIZE = 3;

class Exam {
	Task tasks[ARRAY_SIZE];
	unsigned minPoints;

public:
	Exam();
	Exam(const Task* tasks, unsigned minPoints);

	void setPoints(unsigned minPoints);

	void changeMin(const unsigned minPoints);
	unsigned getMax();

	void writeToFile(const char* filename) const;
	void readFromFile(const char* filename);

	void print();
};