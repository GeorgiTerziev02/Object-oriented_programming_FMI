#pragma once
#include "Student.h"
#include "Teacher.h"

const short MAX_ASSISTANTS_COUNT = 3;

class OOPcourse {
private:
    Student** students;
    int size;
    int capacity;
    Teacher lecturer;
    Teacher assistants[MAX_ASSISTANTS_COUNT];
public:
    OOPcourse(const MyString& lecturerName, const Teacher& assistant, int capacity);
    OOPcourse(const MyString& lecturer, const MyString& assistant);

    ~OOPcourse();
    void addStudent(const MyString&, int fn);
    void removeStudent(int fn);
    void addGrade(int fn, const MyString& task, double grade, const MyString& teacher);

    double getAverageForCourse() const;
    double getAverageGradePerTask(const MyString& task) const;
    double getAverageFromTeacher(const MyString& teacher) const;
    double getAverage(bool (*filterFunc)(const Grade&, const MyString&), const MyString& param) const;
};

