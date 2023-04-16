#pragma once
#include "PersonInfo.h"

class Grade
{
	double grade = 2;
	PersonInfo teacher;
	char* taskName = nullptr;

	void free();
	void freeTaskName();

	void copyFrom(const Grade&);

	void setTaskName(const char* name);
	void setTeacher(const char* name);

public:
	Grade() = default;
	Grade(const char* teacherName, const char* taskName, double grade);
	Grade(const Grade& other);

	Grade& operator=(const Grade& other);

	void setGrade(double grade);
	double getGrade() const;
	const char* getTaskName() const;
	const char* getTeacherName() const;

	~Grade();
};

