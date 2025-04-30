#pragma once
#include "Student.h"

class ClassOfStudents {
private:
	static constexpr size_t DEFAULT_SIZE = 16;

	Student** students = nullptr;
	size_t count = 0;
	size_t capacity = DEFAULT_SIZE;

	void resize(size_t leastCapacity);
public:
	ClassOfStudents();
	ClassOfStudents(const ClassOfStudents& other);
	ClassOfStudents(ClassOfStudents&& other) noexcept;
	ClassOfStudents& operator=(const ClassOfStudents&);
	ClassOfStudents& operator=(ClassOfStudents&&) noexcept;
	~ClassOfStudents();

	void addStudent(const Student&);
	void addStudent(Student&&);
	void insertAt(const Student&, size_t);
	void insertAt(Student&&, size_t);
	size_t getFirstFreeIndex() const;
	void removeAt(size_t index);

private:
	void free();
	void copyFrom(const ClassOfStudents&);
	void moveFrom(ClassOfStudents&&) noexcept;
};

