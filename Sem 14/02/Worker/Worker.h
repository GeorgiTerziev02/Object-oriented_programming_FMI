#pragma once
#include "Employee.h"

class Worker : public Employee
{
	unsigned int monthsWorked;
public:
	Worker();
	Worker(const MyString& name, int age, double salary, unsigned int monthsWorked);

	Employee* clone() const override;
	void print() const override;

	unsigned int getMonthsWorked() const;
};

