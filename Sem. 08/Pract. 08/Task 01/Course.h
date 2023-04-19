#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Grade.h"
const unsigned short MAX_ASSISTANTS_AMOUNT = 3;

class Course
{
	Teacher lecturer;
	Teacher assistants[MAX_ASSISTANTS_AMOUNT];
	Student** students;
	Grade** courseGrades;
	unsigned short assistantsCount;
	size_t studentsCount;
	size_t studentsCapacity;
	size_t courseGradesCount;
	size_t courseGradesCapacity;

public:
	Course();
	Course(const char* lecturerName, const char* assistant1 = nullptr, const char* assistant2 = nullptr, const char* assistant3 = nullptr);
	Course(const Course& other);
	Course& operator=(const Course& other);
	~Course();

	void addStudent(const char* name, unsigned int facultyNumber);
	void removeStudent(unsigned int facultyNumber);
	void addGrade(unsigned int facultyNumber, const char* task, double value, const char* teacherName);
	void editGrade(unsigned int facultyNumber, const char* task, double newValue);
	Grade& findGrade(unsigned int facultyNumber, const char* task);
	Student& getStudentByFacultyNumber(unsigned int facultyNumber);

	const double getAverageGradeForCourse() const;
	const double getAverageGradePerTask(const char* task) const;
	const double getAverageGradeFromTeacher(const char* teacherName) const;

private:
	void free();
	void copyFrom(const Course& other);
	void resizeStudents();
	void resizeGrades();

	const size_t getIndexOfStudentByFacultyNumber(unsigned int facultyNumber) const;
	const Teacher& getTeacherByName(const char* teacherName) const;
};

