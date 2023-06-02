#include "Trainee.h"
#include <iostream>

Trainee::Trainee(const MyString& name, unsigned int age, double salary, unsigned int daysLeftOfInternship)
        :Employee(name, age, salary) , daysLeftOfInternship(daysLeftOfInternship) {}

Trainee::Trainee()
        :Trainee("",0,0.0,0) {}

Employee* Trainee::clone() const
{
    return new Trainee(*this);
}

void Trainee::print() const
{
    std::cout << "Trainee: " << std::endl;
    Employee::print();
    std::cout << "Days left of internship: " << this->daysLeftOfInternship << std::endl;
    std::cout << std::endl;
}

unsigned int Trainee::getDaysLeftOfInternship() const
{
    return daysLeftOfInternship;
}
