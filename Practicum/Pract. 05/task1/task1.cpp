#include "./task1.h"

Teacher::Teacher()
{
    strcpy_s(name, "GOSHO");
    age = 43;
    subject = DIS;
    salary = 5000.0;
}

Teacher::Teacher(const char* newName, int newAge, Subject newSubject, double newSalary)
{
    setName(newName);
    setAge(newAge);
    setSubject(newSubject);
    setSalary(newSalary);
}

const char* Teacher::getName() const
{
    return name;
}

int Teacher::getAge() const
{
    return age;
}

Subject Teacher::getSubject() const
{
    return subject;
}

double Teacher::getSalary() const
{
    return salary;
}

void Teacher::setName(const char* newName)
{
    if (newName)
    {
        strncpy_s(name, newName, MAX_NAME_LENGTH - 1);
        name[MAX_NAME_LENGTH - 1] = '\0';
    }
}

void Teacher::setAge(int newAge)
{
    if (newAge >= 18 && newAge <= 70)
    {
        age = newAge;
    }
}

void Teacher::setSubject(Subject newSubject)
{
    subject = newSubject;
}

void Teacher::setSalary(double newSalary)
{
    if (newSalary > 500)
    {
        salary = newSalary;
    }
}


int main() {
    Teacher TheBestTeacher;
    cout << "Name: " << TheBestTeacher.getName() << endl;
    cout << "Age: " << TheBestTeacher.getAge() << endl;
    cout << "Subject: " << TheBestTeacher.getSubject() << endl;
    cout << "Salary: " << TheBestTeacher.getSalary() << endl;
    cout << endl;

    return 0;
}
