#include "Teacher.h"

Teacher::Teacher() :teacherName("") {}

Teacher::Teacher(const MyString& name) : teacherName(name) {}

const MyString& Teacher::getTeacherName() const
{
    return teacherName;
}

bool Teacher::operator==(const Teacher& other) const
{
    return teacherName == other.teacherName;
}
