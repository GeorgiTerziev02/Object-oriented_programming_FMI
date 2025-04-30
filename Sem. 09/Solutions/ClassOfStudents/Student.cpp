#include "Student.h"

Student::Student(const MyString& name, unsigned age)
	: name(name), age(age) { }

Student::Student(MyString&& name, unsigned age)
	: name(std::move(name)), age(age) { }

const MyString& Student::getName() const {
	return name;
}

unsigned Student::getAge() const {
	return age;
}