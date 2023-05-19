#pragma once
#include "../Name/Name.h"

const unsigned MAX_GRADE_COUNT = 7;

class Student {
private:
    Name _name;
//    unsigned _grades[MAX_GRADE_COUNT];
    unsigned _gradesCount;
    unsigned _fac;

public:
    Student(const char *name, unsigned fac);

    void setName(const char *name);
    void addGrade();

    unsigned getFac() const;
};
