#pragma once
#include "Employee.h"

class Trainee : public Employee
{
	unsigned int daysLeftOfInternship;
public:
	Trainee(const MyString& name, unsigned int age, double salary, unsigned int daysLeftOfInternship);
	Trainee();
	Employee* clone() const override;
	void print() const override;

	unsigned int getDaysLeftOfInternship() const;
};

