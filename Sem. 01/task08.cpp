#include <iostream>
#include "Source.h"

using std::cin;
using std::cout;
using std::endl;

const unsigned int MAX_SIZE = 30;

namespace StudentNs
{
	struct Student 
	{
		char name[MAX_SIZE];
		char surname[MAX_SIZE];
		double grade;
	};

	void createStudent(Student& student)
	{
		cin >> student.name >> student.surname >> student.grade;
		//validateGrade(student.grade);
	}
}

namespace GroupNs 
{
	struct Group 
	{
		int numStudents;
		double averageGrade;
		StudentNs :: Student* students;
	};

	void validateGrade(double a)
	{
		if (a < 2.0 && a > 6.0)
		{
			cout << -1;
		}
	}

	double calculateAverageGroupScore(StudentNs::Student* students, const int& countStudents)
	{
		double sum = 0;
		for (int32_t i = 0; i < countStudents; i++) 
		{
			sum += students[i].grade;
		}
		return sum / countStudents;
	}

	void createGroup(Group& group)
	{
		cin >> group.numStudents;
		group.students = new StudentNs:: Student[group.numStudents];
		
		for (int i = 0; i < group.numStudents; i++)
		{
			cout << "Enter student # " << i + 1 << "name, surname and grade: " << endl;
			createStudent(group.students[i]);
			validateGrade(group.students[i].grade);
			
		}
		double totalGrade = calculateAverageGroupScore(group.students, group.numStudents);
		validateGrade(totalGrade);
	}

	int ScholarshipStudents(const Group& group, const double& minGrade)
	{
	    int count = 0;
		for (int i = 0; i < group.numStudents; i++)
		{
			if (group.students[i].grade >= minGrade) 
			{
				count++;
			}
		}
		return count;
    }	

	void Sort(StudentNs::Student* student, int n)
	{
		StudentNs::Student temp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j + 1 < n - i; j++)
			{
				if (student[j].grade < student[j + 1].grade)
				{
					temp = student[j];
					student[j] = student[j + 1];
					student[j + 1] = temp;
				}
			}
		}
	}

	void printScholarshipStudents(const Group& group, double& minGrade)
	{
		StudentNs::Student* schStudents = new StudentNs::Student[group.numStudents];
		int count = 0;

		for (size_t i = 0; i < group.numStudents; i++)
		{
			if (group.students[i].grade >= minGrade)
			{
			   schStudents[count] = group.students[i];
			   count++;
			}
		}

		Sort(schStudents, count);

		for (size_t i = 0; i < count; i++)
		{
			cout << schStudents[i].name << " " << schStudents[i].surname << " " << schStudents[i].grade << endl;
		}
		delete[] schStudents;
	}
}

int main()
{
	GroupNs :: Group group;
	createGroup(group);

	cout << "Group average grade: " << group.averageGrade << endl;
	double minGrade;
	cin >> minGrade;

	int numSchStudent = ScholarshipStudents(group, minGrade);
	cout << "Number of scholarship students: " << numSchStudent << endl;
	printScholarshipStudents(group, minGrade);

	delete[] group.students;
	return 0;
}