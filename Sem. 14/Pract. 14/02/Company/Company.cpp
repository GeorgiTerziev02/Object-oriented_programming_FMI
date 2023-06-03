#include "Company.h"
#include <iostream>

namespace {
    template <typename T>
    void customSort(Vector<T*>& employees) 
    {
        int n = employees.getSize();
        bool swapped;

        for (int i = 0; i < n - 1; ++i) 
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (employees[j]->getSalary() > employees[j + 1]->getSalary())
                {
                    std::swap(employees[j], employees[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) 
            {
                break;
            }
        }
    }

}

void Company::copyFrom(const Company& other)
{
    for (size_t i = 0; i < other.employees.getSize(); i++)
    {
        employees.pushBack(other.employees[i]->clone());
    }
}

void Company::moveFrom(Company&& other)
{
    employees = other.employees;

    other.employees = Vector<Employee*>();
}

void Company::free()
{
    for (size_t i = 0; i < employees.getSize(); i++)
    {
        delete employees[i];
    }
    employees.clear();
}

Company::~Company()
{
	for (size_t i = 0; i < employees.getSize(); i++)
	{
		delete employees[i];
	}
}

Company::Company() : ceo("", 0, 0.0, Vector<Manager*>()) {}

Company::Company(const Company& other)
{
    copyFrom(other);
}

Company& Company::operator=(const Company& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Company::Company(Company&& other) noexcept
{
    moveFrom(std::move(other));
}

Company& Company::operator=(Company&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

void Company::addEmployee(Employee* employee)
{
    employees.pushBack(employee);
    customSort(employees);
}

double Company::calculateAverageSalary() const
{
    if (employees.empty())
        return 0.0;

    double sum = 0.0;
    for (int i = 0; i < employees.getSize(); i++) 
    {
        sum += employees[i]->getSalary();
    }

    return sum / employees.getSize();
}

bool Company::hasTwoEmployeesWithSumSalary(double val) const
{
    for (size_t i = 0; i < employees.getSize() - 1; ++i) 
    {
        for (size_t j = i + 1; j < employees.getSize(); ++j) 
        {
            if (employees[i]->getSalary() + employees[j]->getSalary() == val)
                return true;
        }
    }

    return false;
}

//Manager class

void Company::Manager::copyFrom(const Manager& other)
{
    for (size_t i = 0; i < other.subordinates.getSize(); i++)
    {
        subordinates.pushBack(other.subordinates[i]->clone());
    }
}

void Company::Manager::moveFrom(Manager&& other)
{
    subordinates = other.subordinates;

    other.subordinates = Vector<Employee*>();
}

void Company::Manager::free()
{
    for (size_t i = 0; i < subordinates.getSize(); i++)
    {
        delete subordinates[i];
    }
}

Company::Manager::Manager(const MyString& name, unsigned int age, double salary, Vector<Employee*> subordinates)
        : Employee(name, age, salary), subordinates(subordinates) {}

Company::Manager::Manager(const Manager& other)
{
    copyFrom(other);
}

Company::Manager& Company::Manager::operator=(const Manager& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Company::Manager::Manager(Manager&& other) noexcept
{
    moveFrom(std::move(other));
}

Company::Manager& Company::Manager::operator=(Manager&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

void Company::Manager::addSubordinate(Employee* subordinate)
{
    subordinates.pushBack(subordinate);
}

void Company::Manager::print() const
{
    std::cout << "Manager: " << std::endl;
    Employee::print();
    std::cout << "Responsible for employees: " << std::endl;
    for (size_t i = 0; i < subordinates.getSize(); i++)
    {
        std::cout << "\tEmployee " << i + 1 << ":" << std::endl;
        subordinates[i]->print();
    }
    std::cout << std::endl;
}

Employee* Company::Manager::clone() const
{
    return new Manager(*this);
}

Company::Manager::~Manager()
{
    for (size_t i = 0; i < subordinates.getSize(); i++)
    {
        delete subordinates[i];
    }
}

//

//CEO

Company::CEO::CEO(const MyString& name, unsigned int age, double salary, Vector<Manager*> subordinates)
        : Employee(name, age, salary), managers(subordinates) {}

Company::CEO::CEO(const CEO& other)
{
    copyFrom(other);
}

Company::CEO& Company::CEO::operator=(const CEO& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Company::CEO::CEO(CEO&& other) noexcept
{
    moveFrom(std::move(other));
}

Company::CEO& Company::CEO::operator=(CEO&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

void Company::CEO::copyFrom(const CEO& other)
{
    for (size_t i = 0; i < other.managers.getSize(); i++)
    {
        managers.pushBack(other.managers[i]);
    }
}

void Company::CEO::moveFrom(CEO&& other)
{
    managers = other.managers;
    other.managers = Vector<Manager*>();
}

void Company::CEO::free()
{
    for (size_t i = 0; i < managers.getSize(); i++)
    {
        delete managers[i];
    }
}

Company::CEO::CEO() : Employee(), managers() {}

void Company::CEO::addSubordinate(Manager* subordinate)
{
    managers.pushBack(subordinate);
}

void Company::CEO::print() const
{
    std::cout << "CEO: " << std::endl;
    Employee::print();
    std::cout << "Responsible for managers: " << std::endl;
    for (size_t i = 0; i < managers.getSize(); i++)
    {
        std::cout << "\tManager " << i + 1 << ":" << std::endl;
        managers[i]->print();
    }
    std::cout << std::endl;
}

Employee* Company::CEO::clone() const
{
    return new CEO(*this);
}

Company::CEO::~CEO()
{
    for (size_t i = 0; i < managers.getSize(); i++)
    {
        delete managers[i];
    }
}

//
