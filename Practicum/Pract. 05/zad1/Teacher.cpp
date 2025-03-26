#include "Teacher.h"
#include <cstring>



Teacher::Teacher(const char name[], unsigned age, Subject subject, unsigned salary)
{
	setName(name);
	setAge(age);
	setSubject(subject);
	setSalary(salary);
}


const char* Teacher::getName() const
{
	return this->name;
}
void Teacher::setName(const char* name)
{

	if (name && strlen(name))
		strcpy(this->name, name);
}

unsigned Teacher::getAge() const
{
	return this->age;
}


void Teacher::setAge(unsigned age)
{
	if (age >= 18 && age <= 70)
	{
		this->age = age;
	}
}

Subject Teacher::getSubject() const
{
	return this->subject;
}

void Teacher::setSubject(Subject subject)
{
	if ((int)subject > (int)Subject::UNKNOWN && (int)subject < (int)Subject::COUNT)
	{
		this->subject = subject;
	}
}

unsigned Teacher::getSalary() const
{
	return this->salary;
}

void Teacher::setSalary(unsigned salary) 
{
	if (salary <= 10000)
	{
		this->salary = salary;
	}
}