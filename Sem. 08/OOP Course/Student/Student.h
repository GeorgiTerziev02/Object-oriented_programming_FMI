#pragma once
#include "MyString.h"
#include "Grade.h"

const short MAX_GRADES = 7;

class Student
{
private:
	MyString name;
	unsigned int fn;
	Grade grades[MAX_GRADES];
	unsigned int numGrades;
	double averageGrade;
public:
	Student();
	Student(const MyString& name, int facNumber);

	void setName(const MyString& name);
	void setFn(unsigned int fn);
	void setGrades(const Grade* grades, unsigned int gradesdCount);

	const MyString& getName() const;
	unsigned int getFn() const;
	const Grade& getGrades(int index) const;
	const Grade& getGrade(unsigned int index) const;
	double getAverageGrade() const;
	unsigned int getGradesCount() const;

	void addGrade(double score, const MyString& task, const Teacher& teacher);
};