#include "Worker.h"
#include <iostream>

Worker::Worker()
       :Worker("", 0, 0.0, 0) {}

Worker::Worker(const MyString& name, int age, double salary, unsigned int monthsWorked)
       :Employee (name, age, salary), monthsWorked(monthsWorked) {}

Employee* Worker::clone() const
{
    return new Worker(*this);
}

void Worker::print() const
{
    std::cout << "Worker: " << std::endl;
    Employee::print();
    std::cout << "Months worked: " << this->monthsWorked << std::endl;
    std::cout << std::endl;
}

unsigned int Worker::getMonthsWorked() const
{
    return monthsWorked;
}
