#include "Grade.h"
#include "Util.h"


void Grade::free() {

	delete[] task;
	task = nullptr;
	value = 0;
}

void Grade::copyFrom(const Grade& other) {

	Util::copyDynamicCharArray(this->task, other.task);
	this->value = other.value;
	this->teacher = other.teacher;
}

Grade::Grade(const char* task, double value, const Teacher& teacher):teacher(teacher) {
	setTask(task);
	setValue(value);
}

Grade::Grade(const Grade& other) {
	copyFrom(other);
}

Grade& Grade::operator=(const Grade& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Grade::~Grade() {
	free();
}

const char* Grade::getTask() const {
	return this->task;
}

double Grade::getValue() const {
	return this->value;
}

const Teacher& Grade::getTeacher() const {
	return this->teacher;
}

void Grade::setTask(const char* task) {
	if (!task) {
		return;
	}
	 
	delete[] this->task;
	Util::copyDynamicCharArray(this->task, task);
}

void Grade::setValue(double value) {
	this->value = value;
}