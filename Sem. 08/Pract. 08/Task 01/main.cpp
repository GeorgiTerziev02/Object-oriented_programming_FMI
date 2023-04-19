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

    course.editGrade(42069, "HW1", 5); // student with this faculty number is removed, 
                                        //but grade exists, so program catches the error, 
                                        //prints out a message and still edits the grade

    std::cout << course.getAverageGradePerTask("HW1") << std::endl; // 5.5;

    std::cout << course.getAverageGradeFromTeacher("Lecturer1") << std::endl; //6

    course.editGrade(00666, "HW1", 5);//edits grade to 5, therefore average grade from lecturer1 will be different

    std::cout << course.getAverageGradeFromTeacher("Lecturer1") << std::endl; //5
    
}