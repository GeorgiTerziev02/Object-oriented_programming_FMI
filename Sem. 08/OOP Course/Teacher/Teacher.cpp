#include "Teacher.h"

Teacher::Teacher() :teacherName("") {}

Teacher::Teacher(const MyString& name)
{
    this->teacherName = name;
}

MyString Teacher::getTeacherName() const
{
    return teacherName;
}

bool Teacher::operator==(const Teacher& other) const
{
    return teacherName == other.teacherName;
}
