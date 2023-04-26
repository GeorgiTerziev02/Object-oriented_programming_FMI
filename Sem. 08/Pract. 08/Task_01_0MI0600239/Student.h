#include <iostream>
#include "Grade.h"
#pragma once

class Student
{
	char* name;
	unsigned fn;
	Grade grades[7];
	int countGrades;

	void free();
	void copyFrom(const Student& other);

public:
	Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void setName(const char* name);
	void setFn(unsigned fn);

	unsigned getFn()const;
	const char* getName() const;
	const Grade* getGrades() const;
	int getCountGrades() const;

	double getGradesSum() const;
	void addGrade(const Grade& grade);
	
	double getTaskGrade(const char* task) const;
	double getTeacherGrade(const char* teacher) const;
};

