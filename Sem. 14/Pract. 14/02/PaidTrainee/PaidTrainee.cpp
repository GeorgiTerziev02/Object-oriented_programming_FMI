#include "PaidTrainee.h"
#include <iostream>

PaidTrainee::PaidTrainee()
    : PaidTrainee("", 0, 0.0, 0, 0) {}

PaidTrainee::PaidTrainee(const MyString& name, int age, double salary, int daysRemaining, double rating)
    : Trainee(name, age, salary, daysRemaining), rating(rating) {}

Employee* PaidTrainee::clone() const
{
    return new PaidTrainee(*this);
}

void PaidTrainee::print() const
{
    std::cout << "Paid Trainee: " << std::endl;
    Employee::print();
    std::cout << "Days left of internship: " << getDaysLeftOfInternship() << std::endl;
    std::cout << "Rating: " << this->rating << std::endl;
    std::cout << std::endl;
}

unsigned int PaidTrainee::getRating() const
{
    return rating;
}

void PaidTrainee::setRating(unsigned int rating)
{
    if (rating > 100)
        throw std::out_of_range("Invalid rating number!");
    this->rating = rating;
}

