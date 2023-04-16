#include "Course.h"
#include "Student.h"
#include "PersonInfo.h"

#include <cstring>
#include <iostream>
#include <stdexcept>

void Course::free()
{
	for (unsigned i = 0; i < numberOfStudents; i++)
		delete students[i];
	delete[] students;
}

void Course::copyFrom(const Course& other)
{
	lecturer = PersonInfo(other.lecturer);
	numberOfAssistants = other.numberOfAssistants;
	numberOfStudents = other.numberOfStudents;

	for (unsigned i = 0; i < numberOfAssistants; i++)
		assistants[i] = other.assistants[i];

	for (unsigned i = 0; i < numberOfStudents; i++)
		students[i] = new Student(*other.students[i]);
}

Course::Course(const char* lecturerName)
{
	lecturer = PersonInfo(lecturerName);

	students = new Student * [capacityOfStudents];
}

Course::Course(const char* lecturerName, const char* assistantName) : Course(lecturerName)
{
	assistants[numberOfAssistants++] = PersonInfo(assistantName);
}

Course::Course(const char* lecturerName, const char* firstAssistantName, const char* secondAssistantName) : Course(lecturerName, firstAssistantName)
{
	assistants[numberOfAssistants++] = PersonInfo(secondAssistantName);
}

Course::Course(const char* lecturerName, const char* firstAssistantName, const char* secondAssistantName, const char* thirdAssistantName) : Course(lecturerName, firstAssistantName, secondAssistantName)
{
	assistants[numberOfAssistants++] = PersonInfo(thirdAssistantName);
}

Course::Course(const Course& other)
{
	copyFrom(other);
}

void Course::resize()
{
	capacityOfStudents *= 2;
	Student** temp = new Student* [capacityOfStudents];
	for (unsigned i = 0; i < numberOfStudents; i++)
		temp[i] = students[i];
	delete[] students;
	students = temp;
}

int Course::findIndexFromFN(unsigned fn) const
{
	int index = -1;

	for (unsigned i = 0; i < numberOfStudents; i++)
		if ((*students[i]).getFN() == fn)
			index = i;

	return index;
}

bool Course::isTeacherNameValid(const char* teacherName) const
{
	if (strcmp(lecturer.getName(), teacherName) == 0)
		return true;

	for (unsigned i = 0; i < numberOfAssistants; i++)
		if (strcmp(assistants[i].getName(), teacherName) == 0)
			return true;

	return false;
}

void Course::addStudent(const char* name, unsigned fn)
{
	if (numberOfStudents == capacityOfStudents)
		resize();

	students[numberOfStudents++] = new Student(name, fn);
}

void Course::addGrade(unsigned fn, const char* taskName, double grade, const char* teacherName)
{
	int index = findIndexFromFN(fn);

	if (index == -1)
		throw std::invalid_argument("There is not a student with that facultity number!\n");

	if (!isTeacherNameValid(teacherName))
		throw std::invalid_argument("There is not a teacher with that name!\n");

	(*students[index]).addGrade(grade, taskName, teacherName);
}

double Course::getAvarageGrade() const
{
	double result = 0;

	for (unsigned i = 0; i < numberOfStudents; i++)
		result += (*students[i]).getSumOfGrades();

	return result / (double)numberOfStudents;
}

double Course::getAvarageGradeFromTeacher(const char* teacherName) const
{
	double result = 0;
	unsigned countOfGrades = 0;
	for (unsigned i = 0; i < numberOfStudents; i++)
	{
		double sumOfGrades = (*students[i]).getSumOfGradesPerTeacher(teacherName, countOfGrades);
		if (sumOfGrades > 0.000001)
		{
			result += sumOfGrades;
		}
	}
	return result / (double)countOfGrades;
}

double Course::getAvarageGradePerTask(const char* taskName) const
{
	double result = 0;
	unsigned countOfGrades = 0;
	for (unsigned i = 0; i < numberOfStudents; i++)
	{ 
		double sumOfGrades = (*students[i]).getSumOfGradesPerTask(taskName, countOfGrades);
		if (sumOfGrades > 0.000001)
		{
			result += sumOfGrades;
		}
	}

	return result / (double)countOfGrades;
}

void Course::removeStudent(unsigned fn)
{
	int index = findIndexFromFN(fn);

	if (index == -1)
		throw std::invalid_argument("There is not a student with that facultity number!\n");

	delete students[index];
	students[index] = nullptr;

	for (; index < numberOfStudents - 1; index++)
	{
		Student* temp = students[index];
		students[index] = students[index + 1];
		students[index + 1] = temp;
	}

	numberOfStudents--;
}

Course::~Course()
{
	free();
}