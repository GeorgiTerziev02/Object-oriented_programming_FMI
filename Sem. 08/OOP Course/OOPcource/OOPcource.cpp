#include "OOPcource.h"

OOPcourse::OOPcourse(const MyString& lecturerName, const Teacher& assistant, int capacity) :
	size(0), capacity(capacity), lecturer(lecturerName), assistants{ assistant, Teacher(), Teacher() }
{
	students = new Student * [capacity];
}

OOPcourse::OOPcourse(const MyString& lecturer, const MyString& assistant) 
{
	this->size = 0;
	this->capacity = 10;
	this->students = new Student * [this->capacity];
	this->lecturer = Teacher(lecturer);
	this->assistants[0] = Teacher(assistant);
}

OOPcourse::~OOPcourse()
{
	for (int i = 0; i < size; i++)
	{
		delete students[i];
	}
	delete[] students;
}

void OOPcourse::addStudent(const MyString& name, int fn)
{
	if (size >= capacity)
	{
		return;
	}
	students[size++] = new Student(name, fn);
}


void OOPcourse::removeStudent(int fn)
{
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getFn() == fn)
		{
			delete students[i];
			students[i] = students[size - 1];
			size--;
			return;
		}
	}
}

void OOPcourse::addGrade(int fn, const MyString& task, double grade, const MyString& teacher)
{
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getFn() == fn)
		{
			Teacher* t = &lecturer;
			for (int j = 0; j < MAX_ASSISTANTS_COUNT; j++)
			{
				if (assistants[j].getTeacherName() == teacher)
				{
					t = &assistants[j];
					break;
				}

			}
			students[i]->addGrade(grade, task, teacher);
			return;
		}
	}
}

bool includeAllGrades(const Grade& grade, const MyString& task = "") 
{
	return true;
}

bool includeGradesForTask(const Grade& grade, const MyString& task)
{
	return grade.getSubject() == task;
}

bool includeGradesFromTeacher(const Grade& grade, const MyString& teacher) 
{
	return grade.getTeacher() == teacher;
}

double OOPcourse::getAverageForCourse() const
{
	return getAverage(includeAllGrades, "");
}

double OOPcourse::getAverageGradePerTask(const MyString& task) const
{
	return getAverage(includeGradesForTask, task);
}

double OOPcourse::getAverageFromTeacher(const MyString& teacher) const
{
	return getAverage(includeGradesFromTeacher, teacher);
}

double OOPcourse::getAverage(bool (*filterFunc)(const Grade&, const MyString&), const MyString& param) const
{
	size_t count = 0;
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (unsigned int j = 0; j < students[i]->getGradesCount(); j++)
		{
			const Grade& grade = students[i]->getGrade(j);
			if (filterFunc(grade, param))
			{
				sum += grade.getGrade();
				count++;
			}
		}
	}
	return count > 0 ? sum / count : 0;
}