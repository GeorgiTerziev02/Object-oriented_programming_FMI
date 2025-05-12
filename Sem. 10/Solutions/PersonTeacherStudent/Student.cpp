#include "Student.h"

Student::Student(const char* name, int age, size_t fn) : Person(name, age), fn(fn)
{ }

size_t Student::getFn() const {
	return fn;
}