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

Company::~Company()
{
	for (size_t i = 0; i < employees.getSize(); i++)
	{
		delete employees[i];
	}
}

void Company::addEmployee(Employee* employee)
{
    employees.pushBack(employee);
    customSort(employees);
}

void Company::addWorker(Employee* worker)
{
    addEmployee(worker);
}

void Company::addTrainee(Employee* trainee)
{
    addEmployee(trainee);
}

void Company::addPaidTrainee(Employee* paidTrainee)
{
    addEmployee(paidTrainee);
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

Company::Manager::Manager(const MyString& name, unsigned int age, double salary, Vector<Employee*> subordinates)
        : Employee(name, age, salary), subordinates(subordinates) {}

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

Company::CEO::CEO(const MyString& name, unsigned int age, double salary, Vector<Manager*> subordinates)
        : Employee(name, age, salary), managers(subordinates) {}

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
