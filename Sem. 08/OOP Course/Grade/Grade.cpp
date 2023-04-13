#include "Grade.h"

Grade::Grade()
{
	grade = 0;
}

Grade::Grade(double grade, const Teacher& teacher) : grade(grade), subject(""), teacher(teacher){}

Grade::Grade(double grade, const Teacher& teacher, const MyString& subject)
	: grade(grade), teacher(teacher), subject(subject) {}


void Grade::setGrade(double grade)
{
	this->grade = grade;
}

double Grade::getGrade() const
{
	return grade;
}

Teacher Grade::getTeacher() const
{
	return teacher;
}

MyString Grade::getSubject() const
{
	return subject;
}

void Grade::setSubject(const MyString& subject)
{
	this->subject = subject;
}
