#include "Teacher.h"
#include "Student.h"

#pragma once

const int MAX_COUNT_ASSISTANTS = 3;

class OOPcourse
{
	Teacher lecturer;
	Teacher assistents[MAX_COUNT_ASSISTANTS];
	Student* students;
	int countStudents = 0;
	int capacityArray = 50;

	void free();
	void copyFrom(const OOPcourse& other);

public:
	OOPcourse(const char* lecturer, const char* assistant1 = "\0", const char* assistant2 = "\0", const char* assistant3 = "\0");
	
	OOPcourse() = default;
	OOPcourse(const OOPcourse& other);
	OOPcourse operator=(const OOPcourse& other);
	~OOPcourse();

	void setStudentGrade(unsigned fn, const Grade& grade);

	void addStudent(const char* name, unsigned fn);
	void addGrade(unsigned fn, const char* task, double grade, const char* teacher);
	void removeStudent(unsigned fn);

	void resize();
	void swap(Student& student1, Student& student2);

	int getStudentIndex(unsigned fn) const;
	double getAverageForCourse();
	double getAverageGradePerTask(const char* task);
	double getAverageFromTeacher(const char* teacher);
};


