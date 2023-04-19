#pragma once
#include "Teacher.h"
class Grade
{
	char* task = nullptr;
	double value = 0.0;
	Teacher teacher;
	unsigned int studentFacultyNumber;

public:

	Grade() = default;
	Grade(unsigned int facultyNumber, const char* task, double value, const Teacher& teacher);
	Grade(const Grade& other);
	Grade& operator=(const Grade& other);
	~Grade();

	const char* getTask() const;
	void setTask(const char* task);
	double getValue() const;
	void setValue(double value);
	const Teacher& getTeacher() const;
	const unsigned int getStudentFacultyNumber() const;

private:
	void free();
	void copyFrom(const Grade& other);
};

