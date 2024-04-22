#pragma once

#include "Person.h"

class Teacher : public Person {
private:
	char** subjects;
	size_t subjectsCount;

	void copySubjects(char** subjects, size_t subjectsCount);
public:
	Teacher(const char* name, int age, char** subjects, size_t subjectsCount);

	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);

	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(Teacher&& other) noexcept;
	~Teacher();

private:
	void free();
	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);
};

