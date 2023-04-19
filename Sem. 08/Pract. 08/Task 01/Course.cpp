#include "Course.h"
#include <cstring>
#include <iostream>

const unsigned short INITIAL_STUDENTS_CAPACITY = 5;

void Course::free() {
	for (size_t i = 0; i < studentsCount; i++) {
		delete students[i];
	}

	for (size_t i = 0; i < courseGradesCount; i++) {
		delete courseGrades[i];
	}

	delete[] students;
	delete[] courseGrades;
	studentsCapacity = studentsCount = courseGradesCount = courseGradesCapacity = 0;
	assistantsCount = 0;
}

void Course::copyFrom(const Course& other) {

	this->assistantsCount = other.assistantsCount;
	this->studentsCapacity = other.studentsCapacity;
	this->studentsCount = other.studentsCount;
	this->courseGradesCount = other.courseGradesCount;
	this->courseGradesCapacity = other.courseGradesCapacity;
	this->students = new Student* [studentsCapacity];
	this->courseGrades = new Grade* [courseGradesCount];
	for (size_t i = 0; i < studentsCount; i++) {

		students[i] = new Student(*(other.students[i]));
	}

	for (size_t i = 0; i < courseGradesCount; i++) {
		courseGrades[i] = new Grade(*(other.courseGrades[i]));
	}
}

Course::Course(): assistantsCount(0), studentsCount(0), studentsCapacity(INITIAL_STUDENTS_CAPACITY),
	 courseGradesCount(0), courseGradesCapacity(INITIAL_STUDENTS_CAPACITY) {
	
	students = new Student* [studentsCapacity];
	courseGrades = new Grade* [studentsCapacity];
}

Course::Course(const char* lecturerName, const char* assistant1,
	const char* assistant2, const char* assistant3): lecturer(lecturerName), assistantsCount(0),
	studentsCount(0), studentsCapacity(INITIAL_STUDENTS_CAPACITY),
	courseGradesCount(0), courseGradesCapacity(INITIAL_STUDENTS_CAPACITY) {

	if (assistant1) {
		this->assistantsCount++;
		assistants[0].setName(assistant1);
	}
	if (assistant2) {
		this->assistantsCount++;
		assistants[1].setName(assistant2);
	}
	if (assistant3) {
		this->assistantsCount++;
		assistants[2].setName(assistant3);
	}
	students = new Student* [studentsCapacity];
	courseGrades = new Grade* [studentsCapacity];
}

Course::Course(const Course& other) {
	copyFrom(other);
}

Course& Course::operator=(const Course& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Course::~Course() {
	free();
}

void Course::resizeStudents() {
	studentsCapacity *= 2;
	Student** temp = new Student* [studentsCapacity];
	for (size_t i = 0; i < studentsCount; i++) {
		temp[i] = students[i];
	}

	delete[] students;
	students = temp;
}

void Course::resizeGrades() {
	courseGradesCapacity *= 2;
	Grade** temp = new Grade* [courseGradesCapacity];
	for (size_t i = 0; i < courseGradesCount; i++) {
		temp[i] = courseGrades[i];
	}
	delete[] courseGrades;
	courseGrades = temp;
}

void Course::addStudent(const char* name, unsigned int facultyNumber) {
	if (studentsCount >= studentsCapacity) {
		resizeStudents();
	}

	students[studentsCount++] = new Student(name, facultyNumber);
}

void Course::addGrade(unsigned int facultyNumber, const char* task, double value, const char* teacherName) {

	const size_t studentIndex = getIndexOfStudentByFacultyNumber(facultyNumber);
	if (studentIndex >= studentsCount) {
		throw "Error! No such student found!";
	}
	if (courseGradesCount >= courseGradesCapacity) {
		resizeGrades();
	}
	Grade grade(facultyNumber, task, value, getTeacherByName(teacherName));
	students[studentIndex]->receiveGrade(grade);
	courseGrades[courseGradesCount++] = new Grade(grade);
}

Grade& Course::findGrade(unsigned int facultyNumber, const char* task) {
	for (size_t i = 0; i < courseGradesCount; i++) {
		if (courseGrades[i]->getStudentFacultyNumber() == facultyNumber && strcmp(task, courseGrades[i]->getTask()) == 0) {
			return *courseGrades[i];
		}
	}
	throw std::exception("No such grade!");
}

Student& Course::getStudentByFacultyNumber(unsigned int facultyNumber) {
	for (size_t i = 0; i < studentsCount; i++) {
		if (students[i]->getFacultyNumber() == facultyNumber) {
			return *students[i];
		}
	}
	throw std::exception("No such student!");
}

void Course::editGrade(unsigned int facultyNumber, const char* task, double newValue) {

	Grade& gradeToEdit = findGrade(facultyNumber, task);
	gradeToEdit.setValue(newValue);
	try {
		Student& student = getStudentByFacultyNumber(facultyNumber);
		student.editGrade(task, newValue);
	}
	catch (std::exception e) {
		std::cout << "Grade successfully edited, but student with faculty number " << facultyNumber << " is no longer in this course!" << std::endl;
	}
}


const size_t Course::getIndexOfStudentByFacultyNumber(unsigned int facultyNumber) const {
	for (size_t i = 0; i < studentsCount; i++) {
		if (students[i]->getFacultyNumber() == facultyNumber) {
			return i;
		}
	}
	return studentsCount;
}

void Course::removeStudent(unsigned int facultyNumber) {
	
	const size_t indexToRemove = getIndexOfStudentByFacultyNumber(facultyNumber);

	if (indexToRemove != studentsCount) {
		delete students[indexToRemove];
		students[indexToRemove] = students[studentsCount - 1];
		students[--studentsCount] = nullptr;
	}
}

const Teacher& Course::getTeacherByName(const char* teacherName) const {
	if (strcmp(lecturer.getName(), teacherName) == 0) {
		return lecturer;
	}
	for (size_t i = 0; i < assistantsCount; i++) {
		if (strcmp(assistants[i].getName(), teacherName) == 0) {
			return assistants[i];
		}
	}

	throw "Error! No such teacher found!";
}

const double Course::getAverageGradeForCourse() const {

	if (courseGradesCount == 0) {
		return 0;
	}
	double sum = 0.0;
	for (size_t i = 0; i < courseGradesCount; i++) {
		sum += courseGrades[i]->getValue();
	}
	return sum / courseGradesCount;

}


const double Course::getAverageGradePerTask(const char* task) const {
	
	double sum = 0.0;
	size_t specifiedTaskGradesCounter = 0;

	for (size_t i = 0; i < courseGradesCount; i++) {
		if (strcmp(courseGrades[i]->getTask(), task) == 0) {
			sum += courseGrades[i]->getValue();
			specifiedTaskGradesCounter++;
		}
	}

	return specifiedTaskGradesCounter == 0 ? 0.0 : (sum / specifiedTaskGradesCounter);

	
}

const double Course::getAverageGradeFromTeacher(const char* teacherName) const {

	double sum = 0.0;
	size_t gradesByTeacherCounter = 0;
	for (size_t i = 0; i < courseGradesCount; i++) {
		if (strcmp(courseGrades[i]->getTeacher().getName(), teacherName) == 0) {
			sum += courseGrades[i]->getValue();
			gradesByTeacherCounter++;
		}
	}

	return gradesByTeacherCounter == 0 ? 0.0 : (sum / gradesByTeacherCounter);
}

