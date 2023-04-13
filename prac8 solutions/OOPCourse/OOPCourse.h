#pragma once
#include "../Name/Name.h"
#include "../Student/Student.h"
#include "../Grade/Grade.h"

class OOPcourse {
private:
    Name _teacherName;
    Name _assistantNames[3];
    unsigned _assistantCount;

    Student **_students;
    unsigned _studentsCount;
    unsigned _studentsCapacity;

    Grade **_grades;
    unsigned _gradesCount;
    unsigned _gradesCapacity;

    void copyStudents(Student ** const students, unsigned studentsCount, unsigned studentsCapacity);
    void copyGrades(Grade ** const grades, unsigned gradesCount, unsigned gradesCapacity);
    void copyFrom(const OOPcourse &other);

    void freeStudents();
    void freeGrades();
    void free();

    void resizeStudents();
    void resizeGrades();

public:
    OOPcourse();
    explicit OOPcourse(const char *teacherName);
    OOPcourse(const char *teacherName, const char *assistantOneName);
    OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName);
    OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName, const char *assistantThreeName);
    OOPcourse(const char *teacherName, unsigned assistantCount, const char *assistantOneName, const char *assistantTwoName, const char *assistantThreeName);

    OOPcourse(const OOPcourse &other);
    OOPcourse &operator=(const OOPcourse &other);
    ~OOPcourse();

    void addStudent(const char *studentName, unsigned studentFac);
    void addGrade(unsigned studentFac, const char *assignmentName, unsigned grade, const char *teacherName);

    double getAverageForCourse() const;

    void removeStudent(unsigned studentFac);

    double getAverageGradePerTask(const char *assignmentName) const;
    double getAverageFromTeacher(const char *assignmentName) const;


private:
    unsigned getStudentIndexByFac(unsigned studentFac);

    void removeStudentAtIndex(unsigned index);
    void removeGradeAtIndex(unsigned index);

    void removeGradesByStudentFac(unsigned studentFac);

    double getAverageByCriteria(bool (*compFunc)(const Grade &grade, const char *name), const char *name) const;

};