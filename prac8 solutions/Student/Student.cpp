#include "Student.h"

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
