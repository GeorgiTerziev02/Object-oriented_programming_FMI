#include <iostream>
#include "Grade.h"

#pragma warning(disable: 4996)

void Grade::free()
{
	value = 0;
	delete[] task;
	task = nullptr;
	delete[] teacher;
	teacher = nullptr;
}

void Grade::copyFrom(const Grade& other)
{
	value = other.getValue();

	task = new char[strlen(other.task) + 1];
	strcpy(task, other.task);

	teacher = new char[strlen(other.teacher) + 1];
	strcpy(teacher, other.teacher);
}

Grade::Grade()
{
	value=0;
	task = nullptr;
	teacher = nullptr;
}

Grade::Grade(const Grade& other)
{
	copyFrom(other);
}

Grade& Grade::operator=(const Grade& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Grade::~Grade()
{
	free();
}

Grade::Grade(double value,const char* task,const char* teacher)
{
	setValue(value);
	setCharArray(task, this->task);
	setCharArray(teacher,this->teacher);
}

void Grade::setValue(double grade) {
	if (grade < 2 || grade>6) {
		grade = 2;
	}
	value = grade;
}


void Grade::setCharArray(const char* content, char*& toBeChanged)
{
	if (toBeChanged != nullptr) {
		delete[] toBeChanged;
	}

	toBeChanged = new char[strlen(content) + 1];
	strcpy(toBeChanged, content);
}

double Grade::getValue() const
{
	return value;
}

const char* Grade::getTask() const
{
	return task;
}

const char* Grade::getTeacher() const
{
	return teacher;
}
