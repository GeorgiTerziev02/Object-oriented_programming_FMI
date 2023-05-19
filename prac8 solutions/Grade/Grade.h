#pragma once
#include "../Name/Name.h"

class Grade {
private:
    Name _assignmentName;
    Name _teacherName;

    unsigned _studentFac;
    unsigned _value;

public:
    Grade(const char *assignmentName, const char *teacherName, unsigned studentFac, unsigned value);

    unsigned getValue() const;
    unsigned getStudentFac() const;
    const char *getAssignmentName() const;
    const char *getTeacherName() const;

    void setValue(unsigned value);
};
