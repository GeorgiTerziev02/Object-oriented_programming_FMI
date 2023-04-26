#include "OOPcourse.h"

int main()
{
	OOPcourse p("Lecturer1", "Assistant1");

	p.addStudent("Stoycho Kyosev", 42069);
	p.addStudent("Yavor Alexandrov", 69420);
	p.addStudent("Angel Dimitriev", 00666);

	p.addGrade(42069, "HW1", 4, "Assistant1");
	p.addGrade(00666, "HW1", 6, "Lecturer1");
	p.addGrade(42069, "K1", 5, "Assistant1");

	p.getAverageForCourse(); // 5

	p.removeStudent(42069);

	p.getAverageGradePerTask("HW1"); // 5;

	p.getAverageFromTeacher("Lecturer1"); //6

	int x = 5;
}
