#include "Grade.h"

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

void Grade::setValue(unsigned value) {
    if (value < 2 || value > 6) {
        throw "Value should be between 2 and 6!";
    }

    _value = value;
}
