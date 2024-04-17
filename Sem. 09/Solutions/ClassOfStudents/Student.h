#pragma once
#include "MyString.h"

class Student {
private:
	MyString name;
	int age;
public:
	Student(const MyString& name, int age);
	Student(MyString&& name, int age);
	
	const MyString& getName() const;
	unsigned getAge() const;
};