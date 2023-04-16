#pragma once
#include "PersonInfo.h"
#include "Grade.h"

class Student
{
	PersonInfo studentInfo;
	unsigned fn;
	Grade grades[7];
	unsigned numberOfGrades = 0;

	double getSumOfGradesOnCondition(const char* str, unsigned& countOfGrades, bool (*pred)(const Grade&, const char*)) const;

public:

	Student() = default;
	Student(const char* name, unsigned fn);

	double getAverageGrade() const;
	double getSumOfGrades() const;
	double getSumOfGradesPerTask(const char* taskName, unsigned& countOfGrades) const;
	double getSumOfGradesPerTeacher(const char* teacherName, unsigned& countOfGrades) const;
	const PersonInfo& getPerson() const;
	const char* getName() const;
	unsigned getFN() const;
	const Grade* getGrades() const;

	void addGrade(double grade, const char* taskName, const char* teacherName);
};

