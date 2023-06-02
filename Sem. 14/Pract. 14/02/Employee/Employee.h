#pragma once
#include "MyString.h"

class Employee
{
	MyString name;
	unsigned int age;
	double salary;

public:
	Employee();
	Employee(const MyString& name, unsigned int age, double salary);

	virtual void print() const;
	virtual ~Employee() = default;
	virtual Employee* clone() const = 0;
	const MyString& getName() const;
	unsigned int getAge() const;
	double getSalary() const;

	void setName(const MyString& name);
	void setAge(unsigned int age);
};

