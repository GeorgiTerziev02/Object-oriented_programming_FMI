#include "Employee.h"
#include <iostream>

Employee::Employee()
         :Employee("", 0, 0.0) {}

Employee::Employee(const MyString& name, unsigned int age, double salary)
	: salary(salary)
{
	setName(name);
	setAge(age);
}

void Employee::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Salary: " << this->salary << std::endl;
}

const MyString& Employee::getName() const
{
	return name;
}

unsigned int Employee::getAge() const
{
	return age;
}

double Employee::getSalary() const
{
	return salary;
}

void Employee::setName(const MyString& name)
{
	if (name.length() == 0 || name.length() > 30)
	{
		throw std::out_of_range("The name should be between 0 and 30 characters!");
	}
	this->name = name;
}

void Employee::setAge(unsigned int age)
{
	if (age < 16 || age > 60)
	{
		throw std::out_of_range("The working range is from 16 to 60!");
	}
	this->age = age;
}
