//#include <cstring>
#include "Student.h"

//void Student::copyGrades(const unsigned *grades, unsigned gradesCount) {
//    _gradesCount = gradesCount;
//    for (int i = 0; i < _gradesCount; ++i) {
//        _grades[i] = grades[i];
//    }
//}

void Student::copyFrom(const Student &other) {
    _name.setName(other._name.getName());
//    copyGrades(other._grades, other._gradesCount);
    _gradesCount = other._gradesCount;
    _fac = other._fac;
}

void Student::free() {
    _gradesCount = 0;
    _fac = 0;
}

Student::Student(const Student &other) {
    copyFrom(other);
}

Student &Student::operator=(const Student &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Student::~Student() {
    free();
}

Student::Student(const char *name, unsigned int fac) {
    if (name == nullptr) {
        throw "Invalid name value!";
    }

    _name.setName(name);
    _gradesCount = 0;
    _fac = fac;
}

void Student::setName(const char *name) {
    if (name == nullptr) {
        // throw/handle
    }

    _name.setName(name);
}

void Student::addGrade() {
    if (_gradesCount >= MAX_GRADE_COUNT) {
        throw "Max grades count reached!";
    }

    _gradesCount++;
}

unsigned Student::getFac() const {
    return _fac;
}
