#include "ClassOfStudents.h"

namespace {
    unsigned int getNextPowerOfTwo(unsigned int n) {
        unsigned int step = 1;

        while ((n >> step) > 0) {
            n |= n >> step;
            step *= 2;
        }

        return n + 1;
    }
}

void ClassOfStudents::resize(size_t leastCapacity) {
	size_t newCapacity = getNextPowerOfTwo(leastCapacity);
	Student** newStudents = new Student * [newCapacity] {};
	for (size_t i = 0; i < capacity; i++) {
		newStudents[i] = students[i];
	}
	delete[] students;
	students = newStudents;
	capacity = newCapacity;
}

ClassOfStudents::ClassOfStudents() {
	students = new Student * [capacity];
}

ClassOfStudents::ClassOfStudents(const ClassOfStudents& other) {
	copyFrom(other);
}

ClassOfStudents::ClassOfStudents(ClassOfStudents&& other) noexcept {
	moveFrom(std::move(other));
}

ClassOfStudents& ClassOfStudents::operator=(const ClassOfStudents& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ClassOfStudents& ClassOfStudents::operator=(ClassOfStudents&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

ClassOfStudents::~ClassOfStudents() {
	free();
}

size_t ClassOfStudents::getFirstFreeIndex() const {
	for (size_t i = 0; i < capacity; i++) {
		if(!students[i]) {
			return i;
		}
	}

	throw std::exception("Array is full");
}

void ClassOfStudents::addStudent(const Student& newStudent) {
	if (count == capacity) {
		resize(count + 1);
	}

	size_t firstFreeIndex = getFirstFreeIndex();
	insertAt(newStudent, firstFreeIndex);
}

void ClassOfStudents::addStudent(Student&& newStudent) {
	if (count == capacity) {
		resize(count + 1);
	}

	size_t firstFreeIndex = getFirstFreeIndex();
	insertAt(std::move(newStudent), firstFreeIndex);
}

void ClassOfStudents::insertAt(const Student& newStudent, size_t index) {
	if (index >= capacity) {
		resize(index);
	}

	if (students[index]) {
		// copy assignment operator
		// more optimal than deleting and creating new object
		*students[index] = newStudent;
	}
	else {
		students[index] = new Student(newStudent);
		count++;
	}
}

void ClassOfStudents::insertAt(Student&& newStudent, size_t index) {
	if (index >= capacity) {
		resize(index);
	}

	if (students[index]) {
		// move assignment operator
		// more optimal than deleting and creating new object
		*students[index] = std::move(newStudent);
	}
	else {
		students[index] = new Student(std::move(newStudent));
		count++;
	}
}

void ClassOfStudents::removeAt(size_t index) {
	if (index >= capacity) {
		throw std::out_of_range("Index out of range");
	}

	delete students[index]; // if deleting nullptr does not throw
	students[index] = nullptr;
	count--;
}

void ClassOfStudents::free() {
	for (size_t i = 0; i < capacity; i++) {
		delete students[i]; // if deleting nullptr does not throw
	}

	delete[] students;
}

void ClassOfStudents::copyFrom(const ClassOfStudents& other) {
	capacity = other.capacity;
	count = other.count;
	students = new Student*[capacity] {};
	for (size_t i = 0; i < capacity; i++) {
		if (other.students[i]) {
			students[i] = new Student(*other.students[i]);
		}
	}
}

void ClassOfStudents::moveFrom(ClassOfStudents&& other) {
	capacity = other.capacity;
	count = other.count;
	students = other.students;

	other.capacity = other.count = 0;
	other.students = nullptr;
}
