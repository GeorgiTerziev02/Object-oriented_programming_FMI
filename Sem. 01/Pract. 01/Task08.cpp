#include <iostream>

const int MAX_SIZE_NAME = 30;
const int MAX_GROUP_SIZE = 30;

struct Student
{
	double grade;
	unsigned int FN;
	char name[MAX_SIZE_NAME + 1];
};

struct StudentGroup
{
	Student groupArr[MAX_GROUP_SIZE];
	double averageGrade;
	int amountOfStudents;
};

double findSum(const Student* arr, int numberOfStudents)
{
	double sum = 0;

	for (int i = 0; i < numberOfStudents; i++)
	{
		sum += arr[i].grade;
	}

	return sum;
}

void initGroupOfStudents(StudentGroup& group)
{
	double sumOfGrades;

	for (int i = 0; i < group.amountOfStudents; i++)
	{
		std::cin >> group.groupArr[i].FN;
		std::cin >> group.groupArr[i].name;
		std::cin.ignore();
		std::cin >> group.groupArr[i].grade;
	}

	group.averageGrade = findSum(group.groupArr, group.amountOfStudents) / group.amountOfStudents;
}

int numberOfStudentsTakingScholarship(StudentGroup& group, const double minGrade)
{
	int studentCounter=0;

	for (int i = 0; i < group.amountOfStudents; i++)
	{
		if (group.groupArr[i].grade >= minGrade)
		{
			studentCounter++;
		}
	}

	return studentCounter;
}

void mySwap(Student& a, Student& b)
{
	Student temp = a;
	a = b;
	b = temp;
}

void sortStudentsByGrade(Student* students, const int size)
{
	int min_idx;

	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (students[j].grade < students[min_idx].grade)
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			mySwap(students[min_idx], students[i]);
		}
	}

}

void printStudent(const Student& student)
{
	std::cout << "Faculty number: " << student.FN << ", Name: " << student.name <<
		", Grade: " << student.grade << std::endl;
}

bool isTakingScholarship(Student* students, const int pos, const double minGrade)
{
	return students[pos].grade >= minGrade;
}

void studentsTakingScholarship(StudentGroup& group, const double minGrade)
{
	int numberOfStudents = numberOfStudentsTakingScholarship(group, minGrade);
	sortStudentsByGrade(group.groupArr, group.amountOfStudents);
	for (int i = group.amountOfStudents - 1; i >= numberOfStudents; i--)
	{
		printStudent(group.groupArr[i]);
	}

}

int main()
{
	StudentGroup group;
	std::cin >> group.amountOfStudents;
	initGroupOfStudents(group);
	studentsTakingScholarship(group, 5);
  
  return 0;
}
