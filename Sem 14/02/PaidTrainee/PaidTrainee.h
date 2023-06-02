#pragma once
#include "Trainee.h"

class PaidTrainee : public Trainee
{
	unsigned int rating;
public:
	PaidTrainee();
	PaidTrainee(const MyString& name, int age, double salary, int daysRemaining, double rating);
	Employee* clone() const override;
	void print() const override;

	unsigned int getRating() const;
	void setRating(unsigned int rating);
};