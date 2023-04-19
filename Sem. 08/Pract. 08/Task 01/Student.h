#pragma once
#include "Grade.h"

const unsigned short MAX_GRADES_PER_STUDENT_AMOUNT = 7;

class Student
{
private:

	char* name = nullptr;
	unsigned int facultyNumber = 1;
	Grade grades[MAX_GRADES_PER_STUDENT_AMOUNT];
	size_t gradesCount = 0;

public:

	Student() = default;
	Student(const char* name, unsigned int facultyNumber);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	const char* getName() const;
	void setName(const char* name);
	unsigned int getFacultyNumber() const;
	void setFacultyNumber(unsigned int facultyNumber);
	const size_t getGradesCount() const;
	
	void receiveGrade(const Grade& grade);
	void editGrade(const char* task, double newValue);

	Grade& getGradeByTaskName(const char* task);
	const double getGradeValueByTaskName(const char* task) const;
	
private:

	void free();
	void copyFrom(const Student& other);
};

