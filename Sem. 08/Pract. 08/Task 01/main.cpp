#include "Course.h"
#include "Student.h"
#include <iostream>

int main()
{
    Course course("Lecturer1", "Assistant1");

    course.addStudent("Stoycho Kyosev", 42069);
    course.addStudent("Yavor Alexandrov", 69420);
    course.addStudent("Angel Dimitriev", 00666);
    
    course.addGrade(42069, "HW1", 4, "Assistant1");
    course.addGrade(00666, "HW1", 6, "Lecturer1");
    course.addGrade(42069, "K1", 5, "Assistant1");
    std::cout << course.getAverageGradeForCourse() << std::endl; // 5

    course.removeStudent(42069);

    std::cout << course.getAverageGradePerTask("HW1") << std::endl; // 5;

    std::cout << course.getAverageGradeFromTeacher("Lecturer1") << std::endl; //6
    
}