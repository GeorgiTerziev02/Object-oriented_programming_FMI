#pragma once
#include "../Name/Name.h"

const unsigned MAX_GRADE_COUNT = 7;

class Student {
private:
    Name _name;
//    unsigned _grades[MAX_GRADE_COUNT];
    unsigned _gradesCount;
    unsigned _fac;

//    void copyGrades(const unsigned *grades, unsigned gradesCount);
    void copyFrom(const Student &other);
    void free();

public:
    Student() = default;
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    Student(const char *name, unsigned fac);

    void setName(const char *name);
    void addGrade();

    unsigned getFac() const;
};
