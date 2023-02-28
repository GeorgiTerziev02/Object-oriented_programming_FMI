#include <iostream>

const int MAX_SIZE_NAME = 30;
const int MAX_GROUP_SIZE = 30;

struct Student {
	char name[MAX_SIZE_NAME + 1];
	unsigned int fn;
	double grade;
};

struct StudentGroup {
	int amountOfStudents;
	double averageGrade;
	Student groupArr[MAX_GROUP_SIZE];
};

double findSum(const Student* arr, int numberOfStudents) {
	double sum = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		sum += arr[i].grade;
	}

	return sum;
}

void initGroupOfStudents(StudentGroup& group) {
	for (int i = 0; i < group.amountOfStudents; i++) {
		std::cin >> group.groupArr[i].fn;
		std::cin >> group.groupArr[i].name;
		std::cin.ignore();
		std::cin >> group.groupArr[i].grade;
	}

	group.averageGrade = findSum(group.groupArr, group.amountOfStudents) / group.amountOfStudents;
}

int numberOfStudentsTakingScholarship(const StudentGroup& group, const double minGrade) {
	int studentCounter = 0;

	for (int i = 0; i < group.amountOfStudents; i++) {
		if (group.groupArr[i].grade >= minGrade) {
			studentCounter++;
		}
	}

	return studentCounter;
}

void mySwap(Student& a, Student& b) {
	Student temp = a;
	a = b;
	b = temp;
}

void sortStudentsByGrade(Student* students, const int size) {
	for (int i = 0; i < size - 1; i++) {
		size_t minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (students[j].grade < students[minIndex].grade) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			mySwap(students[minIndex], students[i]);
		}
	}

}

void printStudent(const Student& student) {
	std::cout << "Faculty number: " << student.FN << ", Name: " << student.name <<
		", Grade: " << student.grade << std::endl;
}

void studentsTakingScholarship(StudentGroup& group, const double minGrade) {
	int numberOfStudents = numberOfStudentsTakingScholarship(group, minGrade);
	sortStudentsByGrade(group.groupArr, group.amountOfStudents);
	
	for (int i = group.amountOfStudents - 1; i >= group.amountOfStudents - numberOfStudents; i--) {
		printStudent(group.groupArr[i]);
	}
}

int main() {
	StudentGroup group;
	std::cin >> group.amountOfStudents;
	
	initGroupOfStudents(group);
	studentsTakingScholarship(group, 5);
}
