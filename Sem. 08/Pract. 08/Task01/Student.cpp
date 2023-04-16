#include "Student.h"
#include "PersonInfo.h"
#include "Grade.h"

#include <iostream>
#include <stdexcept>

Student::Student(const char* name, unsigned fn)
{
	studentInfo = PersonInfo(name);
	this->fn = fn;
}

double Student::getAverageGrade() const
{
	double result = 0;

	for (size_t i = 0; i < numberOfGrades; i++)
		result += grades[i].getGrade();

	return result / (double)numberOfGrades;
}

static bool isTaskNameTheSame(const Grade& grade, const char* taskName)
{
	return strcmp(grade.getTaskName(), taskName) == 0;
}

static bool isTeacherNameTheSame(const Grade& grade, const char* teacherName)
{
	return strcmp(grade.getTeacherName(), teacherName) == 0;
}

double Student::getSumOfGradesOnCondition(const char* str, unsigned& countOfGrades, bool (*pred)(const Grade&, const char*)) const
{
	double result = 0;

	for (size_t i = 0; i < numberOfGrades; i++)
	{
		if (pred(grades[i], str))
		{
			result += grades[i].getGrade();
			countOfGrades++;
		}
	}

	return result;
}

double Student::getSumOfGrades() const
{
	double result = 0;

	for (size_t i = 0; i < numberOfGrades; i++)
			result += grades[i].getGrade();

	return result;
}

double Student::getSumOfGradesPerTask(const char* taskName, unsigned& countOfGrades) const
{
	return getSumOfGradesOnCondition(taskName, countOfGrades, isTaskNameTheSame);
}

double Student::getSumOfGradesPerTeacher(const char* teacherName, unsigned& countOfGrades) const
{
	return getSumOfGradesOnCondition(teacherName, countOfGrades, isTeacherNameTheSame);
}
const PersonInfo& Student::getPerson() const
{
	return studentInfo;
}

const char* Student::getName() const
{
	return studentInfo.getName();
}

unsigned Student::getFN() const
{
	return fn;
}

const Grade* Student::getGrades() const
{
	return grades;
}

void Student::addGrade(double grade, const char* taskName, const char* teacherName)
{
	if (numberOfGrades >= 7)
		throw std::out_of_range("You cannot add more grades to that student!\n");

	grades[numberOfGrades++] = Grade(teacherName, taskName, grade);
}