#pragma once
#include "MyString.h"
#include "Teacher.h"

class Grade
{
	MyString subject;
	double grade;
	Teacher teacher;
public:
	Grade();
	Grade(double grade, const Teacher& teacher);
	Grade(double grade, const Teacher& teacher, const MyString& subject);

	void setGrade(double grade);
	double getGrade() const;
	Teacher getTeacher() const;
	MyString getSubject() const;
	void setSubject(const MyString& subject);
};