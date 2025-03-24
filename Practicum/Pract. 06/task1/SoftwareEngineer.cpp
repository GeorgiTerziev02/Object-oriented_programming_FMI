#pragma warning(disable:4996)

#include "SoftwareEngineer.h"

SoftwareEngineer::SoftwareEngineer() {
    setName("Gosho");
    setPosition("CEO");
    setSalary(10000);
}

SoftwareEngineer::SoftwareEngineer(const char* n, const char* p, int s) {
    setName(n);
    setPosition(p);
    setSalary(s);
}

void SoftwareEngineer::setName(const char* n) {
    delete[] name;

    int nLength = strlen(n);
    name = new char[nLength + 1];

    std::strcpy(name, n);
}

const char* SoftwareEngineer::getName() const {
    return name;
}

void SoftwareEngineer::setPosition(const char* p) {
    delete[] position;

    int pLength = strlen(p);
    position = new char[pLength + 1];

    std::strcpy(position, p);
}

const char* SoftwareEngineer::getPosition() const {
    return position;
}

void SoftwareEngineer::setSalary(int s) {
    salary = s;
}

int SoftwareEngineer::getSalary() const {
    return salary;
}
