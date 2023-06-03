#pragma once
#include "Vector.hpp"
#include "Employee.h"

class Company
{
private:
	Vector<Employee*> employees;

	void copyFrom(const Company& other);
	void moveFrom(Company&& other);
	void free();

public:
	~Company();
	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	Company(Company&& other) noexcept;
	Company& operator=(Company&& other) noexcept;


	class Manager : public Employee
	{
		Vector<Employee*> subordinates;

		void copyFrom(const Manager& other);
		void moveFrom(Manager&& other);
		void free();
	public:
		Manager(const MyString& name, unsigned int age, double salary, Vector<Employee*> subordinates);
		Manager(const Manager& other);
		Manager& operator=(const Manager& other);
		Manager(Manager&& other) noexcept;
		Manager& operator=(Manager&& other) noexcept;
		~Manager();

		void addSubordinate(Employee* subordinate);
		void print() const override;
		Employee* clone() const override;
	};

	class CEO : public Employee
	{
		Vector<Manager*> managers;

		void copyFrom(const CEO& other);
		void moveFrom(CEO&& other);
		void free();
	public:
		CEO();
		CEO(const MyString& name, unsigned int age, double salary, Vector<Manager*> subordinates);
		CEO(const CEO& other);
		CEO& operator=(const CEO& other);
		CEO(CEO&& other) noexcept;
		CEO& operator=(CEO&& other) noexcept;
		~CEO();

		void addSubordinate(Manager* subordinate);
		void print() const override;
	    Employee* clone() const override;
	};

	void addEmployee(Employee* employee);
	double calculateAverageSalary() const;
	bool hasTwoEmployeesWithSumSalary(double val) const;

private:
	CEO ceo;
};
