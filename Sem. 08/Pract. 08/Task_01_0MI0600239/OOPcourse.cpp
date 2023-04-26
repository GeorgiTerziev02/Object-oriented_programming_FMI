#include "OOPcourse.h"
#include "Student.h"

void OOPcourse::free()
{
	delete[] students;
	students = nullptr;
}

void OOPcourse::copyFrom(const OOPcourse& other)
{
	lecturer = other.lecturer;
	
	for (int i = 0; i < MAX_COUNT_ASSISTANTS; i++) {
		assistents[i] = other.assistents[i];
	}

	students = new Student[other.capacityArray];

	for (int i = 0; i < other.countStudents; i++) {
		students[i] = other.students[i];
	}

	countStudents = other.countStudents;
	capacityArray = other.capacityArray;
}

OOPcourse::OOPcourse(const char* lecturer, const char* assistant1, const char* assistant2, const char* assistant3) {
	this->lecturer.setName(lecturer);
	this->assistents[0].setName(assistant1);
	this->assistents[1].setName(assistant2);
	this->assistents[2].setName(assistant3);

	students = new Student[capacityArray];
}

OOPcourse::OOPcourse(const OOPcourse& other)
{
	copyFrom(other);
}

OOPcourse OOPcourse::operator=(const OOPcourse& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

OOPcourse::~OOPcourse()
{
	free();
}

void OOPcourse::addStudent(const char* name, unsigned fn) {
	if (countStudents == capacityArray) {
		resize();
	}
	
	students[countStudents].setName(name);
	students[countStudents].setFn(fn);

	countStudents++;
	}

void OOPcourse::addGrade(unsigned fn, const char* task, double grade, const char* teacher) {
	Grade newGrade(grade, task, teacher);

	setStudentGrade(fn, newGrade);
}

double OOPcourse::getAverageForCourse() {
	double result=0;
	for (int i = 0; i < countStudents; i++) {
		result += students[i].getGradesSum();
	}
	return (result/countStudents) ;
}

void OOPcourse::removeStudent(unsigned fn)
{
	int index = getStudentIndex(fn);

	swap(students[index], students[countStudents - 1]);
	countStudents--;
}

void OOPcourse::swap(Student& student1, Student& student2)
{
	Student temp = student1;
	student1 = student2;
	student2 = temp;
}

double OOPcourse::getAverageGradePerTask(const char* task) {
	double result = 0;

	for (int i = 0; i < countStudents; i++) {
		result += students[i].getTaskGrade(task);
	}

	return (result / countStudents);
}

double OOPcourse::getAverageFromTeacher(const char* teacher) {
	double result = 0;

	for (int i = 0; i < countStudents; i++) {
		result += students[i].getTeacherGrade(teacher);
	}

	return (result / countStudents);
}

void OOPcourse::resize() {
	capacityArray *= 2;
	Student* temp = new Student[capacityArray];

	for (int i = 0; i < countStudents; i++) {
		temp[i] = students[i];
	}

	delete[] students;
	students = temp;
	}


void OOPcourse::setStudentGrade(unsigned fn,const Grade& grade) {

	int index = getStudentIndex(fn);

	if (index == -1) {
		return;
	}

	students[index].addGrade(grade);
}

int OOPcourse::getStudentIndex(unsigned fn) const
{
	for (int i = 0; i < countStudents; i++) {
		if (students[i].getFn() == fn) {
			return i;
		}
	}
	return -1;
}
