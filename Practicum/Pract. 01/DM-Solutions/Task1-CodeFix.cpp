#include <iostream>

struct Person
{
    int age;
    short averageGrade;
    bool isStudent;
};

void createPerson(Person& p)
{
    std::cin >> p.isStudent >> p.age >> p.averageGrade;
}

void printStudent(const Person& p)
{
    std::cout << " " << p.isStudent << " " << p.age << " " << p.averageGrade;
}

int main()
{
    Person p;

    createPerson(p);
    printStudent(p);

    Person* personRef = &p;
    delete personRef;
    std::cout << personRef->age;
}