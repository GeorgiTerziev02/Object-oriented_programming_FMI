#pragma once
#include "Teacher.h"
class Grade
{
	char* task = nullptr;
	double value = 0.0;
	Teacher teacher;

public:

	Grade() = default;
	Grade(const char* task, double value, const Teacher& teacher);
	Grade(const Grade& other);
	Grade& operator=(const Grade& other);
	~Grade();

	const char* getTask() const;
	void setTask(const char* task);
	double getValue() const;
	void setValue(double value);
	const Teacher& getTeacher() const;

private:
	void free();
	void copyFrom(const Grade& other);
};

