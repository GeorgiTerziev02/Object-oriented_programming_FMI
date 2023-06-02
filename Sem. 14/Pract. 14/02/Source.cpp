#include <iostream>
#include "Company.h"
#include "Worker.h"
#include "PaidTrainee.h"
#include "Trainee.h"

int main()
{
    Vector<Company::Manager*> managers;
    Vector<Employee*> employeesOf1;
    Vector<Employee*> employeesOf2;

    Company::CEO* ceo = new Company::CEO("CEO", 35, 10000.0, managers);

    Company::Manager* manager1 = new Company::Manager("Manager 1", 26, 8000.0, employeesOf1);
    Worker* employee1 = new Worker("Employee 1", 20, 5000.0, 12);
    PaidTrainee* employee2 = new PaidTrainee("Employee 2", 22, 5500.0, 3, 92);

    manager1->addSubordinate(employee1);
    manager1->addSubordinate(employee2);

    Company::Manager* manager2 = new Company::Manager("Manager 2", 30, 9000.0, employeesOf2);
    Trainee* employee3 = new Trainee("Employee 3", 17 ,0.0, 15);

    manager2->addSubordinate(employee3);

    ceo->addSubordinate(manager1);
    ceo->addSubordinate(manager2);

    ceo->print();

    delete ceo; 

    return 0;
}
