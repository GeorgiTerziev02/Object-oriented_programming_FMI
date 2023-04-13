#include "Student.h"

Student::Student() : name(""), fn(0), numGrades(0)
{
	for (int i = 0; i < MAX_GRADES; i++)
	{
		grades[i] = Grade();
	}
}

Student::Student(const MyString& name, int facNumber)
{
	setName(name);
	setFn(facNumber);
}

void Student::setName(const MyString& name)
{
	this->name = name;
}

void Student::setFn(unsigned int fn)
{
	this->fn = fn;
}

void Student::setGrades(const Grade* grades)
{
	for (size_t i = 0; i < MAX_GRADES; i++)
	{
		this->grades[i] = grades[i];
	}
}

MyString Student::getName() const
{
	return this->name;
}

unsigned int Student::getFn() const
{
	return this->fn;
}

Grade Student::getGrades(int index) const
{
	return this->grades[index];
}

double Student::getAverageGrade() const
{
	double sum = 0;
	for (size_t i = 0; i < numGrades ; i++)
	{
		sum += grades[i].getGrade();
	}
	return sum / numGrades;
}

unsigned int Student::getGradesCount() const
{
	return this->numGrades;
}

void Student::addGrade(double score, const MyString& task, const Teacher& teacher)
{
	if (numGrades == MAX_GRADES)
	{
		return;
	}
	grades[numGrades++] = Grade(score,  teacher, task);
}

Grade Student::getGrade(unsigned int index) const
{
	if (index < 0 || index >= numGrades)
	{
		throw std::out_of_range("Invalid index");
	}
	return grades[index];
}