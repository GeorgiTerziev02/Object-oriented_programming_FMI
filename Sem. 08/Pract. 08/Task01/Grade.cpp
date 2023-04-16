#include "Grade.h"
#include "PersonInfo.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

#pragma warning(disable:4996)

void Grade::freeTaskName()
{
	if (taskName != nullptr)
	{
		delete[] taskName;
		taskName = nullptr;
	}
}

void Grade::free()
{
	freeTaskName();
}

void Grade::copyFrom(const Grade& other)
{
	teacher = other.teacher;
	taskName = new char[strlen(other.taskName) + 1];
	strcpy(taskName, other.taskName);
	grade = other.grade;
}

void Grade::setTaskName(const char* taskName)
{
	freeTaskName();

	this->taskName = new char[strlen(taskName) + 1];

	strcpy(this->taskName, taskName);
}

const char* Grade::getTaskName() const
{
	return taskName;
}

Grade::Grade(const char* teacherName, const char* taskName, double grade)
{
	try
	{
		setGrade(grade);
	}
	catch (const std::invalid_argument& error)
	{
		std::cerr << error.what();
	}
	catch (const std::exception& error)
	{
		std::cerr << "Something went wrong with the system!" << std::endl << error.what();
	}
	setTeacher(teacherName);
	setTaskName(taskName);
}

void Grade::setTeacher(const char* name)
{
	teacher = PersonInfo(name);
}

Grade::Grade(const Grade& other)
{
	copyFrom(other);
}

Grade& Grade::operator=(const Grade& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void Grade::setGrade(double grade)
{
	if (grade - 6.0 >= 0.00000001 || grade - 2.0 <= 0.00000001)
		throw std::invalid_argument("Grade should be between 2.0 and 6.0\n");

	this->grade = grade;
}

double Grade::getGrade() const
{
	return grade;
}

Grade::~Grade()
{
	free();
}

const char* Grade::getTeacherName() const
{
	return teacher.getName();
}