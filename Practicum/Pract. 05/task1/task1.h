#pragma once

#include <iostream>
using namespace std;

static const int MAX_NAME_LENGTH = 50;

enum Subject
{
    DIS,
    ALGEBRA,
    OOOOOOP
};

class Teacher
{
    private:
        char name[MAX_NAME_LENGTH];
        int age;
        Subject subject;
        double salary;

    public:
        Teacher();
        Teacher(const char* newName, int newAge, Subject newSubject, double newSalary);

        const char* getName() const;
        int getAge() const;
        Subject getSubject() const;
        double getSalary() const;

        void setName(const char* newName);
        void setAge(int newAge);
        void setSubject(Subject newSubject);
        void setSalary(double newSalary);
};