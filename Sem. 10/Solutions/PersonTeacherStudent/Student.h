#pragma once
#include "Person.h"

class Student : public Person {
private:
	size_t fn = 0;
public:
	Student(const char* name, int age, size_t fn);
	size_t getFn() const;
};

