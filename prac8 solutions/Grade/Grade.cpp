//#include <cstring>
#include "Grade.h"

void Grade::copyFrom(const Grade &other) {
    _assignmentName.setName(other._assignmentName.getName());
    _teacherName.setName(other._teacherName.getName());
    _studentFac = other._studentFac;
    _value = other._value;
}

void Grade::free() {
    _studentFac = 0;
    _value = 0;
}

Grade::Grade(const Grade &other) {
    copyFrom(other);
}

Grade &Grade::operator=(const Grade &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Grade::~Grade() {
    free();
}

Grade::Grade(const char *assignmentName, const char *teacherName, unsigned int studentFac, unsigned int value) {
    _assignmentName.setName(assignmentName);
    _teacherName.setName(teacherName);
    _studentFac = studentFac;
    _value = value;
}

unsigned Grade::getValue() const {
    return _value;
}

unsigned Grade::getStudentFac() const {
    return _studentFac;
}

const char *Grade::getAssignmentName() const {
    return _assignmentName.getName();
}

const char *Grade::getTeacherName() const {
    return _teacherName.getName();
}
