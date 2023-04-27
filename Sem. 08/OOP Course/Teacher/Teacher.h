#pragma once
#include "MyString.h"

class Teacher
{
    MyString teacherName;
public:
    Teacher();
    Teacher(const MyString& name);
    const MyString& getTeacherName() const;

    bool operator==(const Teacher& other) const;

};

