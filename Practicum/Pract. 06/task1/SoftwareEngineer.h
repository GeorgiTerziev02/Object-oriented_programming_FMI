#pragma once

#include <cstring>

class SoftwareEngineer {
private:
    char* name = nullptr;
    char* position = nullptr;
    int salary;

public:
    SoftwareEngineer();
    SoftwareEngineer(const char* n, const char* p, int s);

    void setName(const char* n);
    const char* getName() const;

    void setPosition(const char* p);
    const char* getPosition() const;

    void setSalary(int s);
    int getSalary() const;
};
