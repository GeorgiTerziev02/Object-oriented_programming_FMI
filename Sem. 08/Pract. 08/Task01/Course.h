#pragma once
#include "Student.h"
#include "PersonInfo.h"

class Course
{
	Student** students;
	PersonInfo lecturer;
	PersonInfo assistants[3];
	unsigned capacityOfStudents = 2;
	unsigned numberOfStudents = 0;
	unsigned numberOfAssistants = 0;

	void free();
	void copyFrom(const Course&);
	void resize();
	int findIndexFromFN(unsigned fn) const;

	bool isTeacherNameValid(const char* teacherName) const;
public:

	Course(const char*);
	Course(const char*, const char*);
	Course(const char*, const char*, const char*);
	Course(const char*, const char*, const char*, const char*);
	Course(const Course&);

	Course& operator=(const Course&) = delete;

	void addStudent(const char*, unsigned);
	void addGrade(unsigned, const char*, double, const char*);

	double getAvarageGrade() const;
	double getAvarageGradeFromTeacher(const char* teacherName) const;
	double getAvarageGradePerTask(const char* taskName) const;

	void removeStudent(unsigned);

	~Course();
};

