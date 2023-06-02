#pragma once
#include "Vector.hpp"
#include "Employee.h"

class Company
{
private:
	Vector<Employee*> employees;

public:
	~Company();

	void addEmployee(Employee* employee);
	void addWorker(Employee* worker);
	void addTrainee(Employee* trainee);
	void addPaidTrainee(Employee* paidTrainee);

	class Manager : public Employee
	{
		Vector<Employee*> subordinates;
	public:
		Manager(const MyString& name, unsigned int age, double salary, Vector<Employee*> subordinates);
		void addSubordinate(Employee* subordinate);
		void print() const override;
		Employee* clone() const override;
		~Manager();
	};


	class CEO : public Employee
	{
		Vector<Manager*> managers;
	public:
		CEO(const MyString& name, unsigned int age, double salary, Vector<Manager*> subordinates);
		CEO();
		void addSubordinate(Manager* subordinate);
		void print() const override;
	    Employee* clone() const override;
		~CEO();
	};

	double calculateAverageSalary() const;
	bool hasTwoEmployeesWithSumSalary(double val) const;

private:
	CEO ceo;
};