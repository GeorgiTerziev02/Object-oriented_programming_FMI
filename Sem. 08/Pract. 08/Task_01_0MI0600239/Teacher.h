#pragma once
#include <iostream>

class Teacher
{
	char* name;

	void free();
	void copyFrom(const Teacher& other);

public:
	Teacher();
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);
	~Teacher();

	void setName(const char* name);
};

