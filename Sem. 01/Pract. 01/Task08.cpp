//task8 from oop practicum 1

#include <iostream>
using std::cout;
using std::cin;
using std::swap;

const int MAX_NAME_SIZE = 999;

namespace Students 
{
	struct Student {
		char name[MAX_NAME_SIZE];
		double averageScore;
	};

	void readStudent(Student& student) {
		cin >> student.name;
		cin >> student.averageScore;
	}
}

namespace Groups {
	using namespace Students;

	struct Group
	{
		int32_t countStudents;
		Student* students;
		double averageScore;
	};

	double calculateAverageGroupScore(Student* students, const int32_t& countStudents) {
		double sum = 0;
		for (int32_t i = 0; i < countStudents; i++) {
			sum += students[i].averageScore;
		}
		return sum / countStudents;
	}

	void readGroup(Group& group) {
		cin >> group.countStudents;

		group.students = new Student[group.countStudents];
		for (int32_t i = 0; i < group.countStudents; i++) {
			readStudent(group.students[i]);
		}

		group.averageScore = calculateAverageGroupScore(group.students, group.countStudents);
	}

	int32_t countStudentsWithScholarShip(const Group& group, const double& minimalAverageScore) {
		int32_t countPassed = 0;

		for (int32_t i = 0; i < group.countStudents; i++) {
			if ((group.students[i].averageScore - minimalAverageScore) >= 0) {
				countPassed++;
			}
		}

		return countPassed;
	}

	void getStudentsWithScholarship(Student* studentsWithScholarship, const Group& group, const double& minimalAverageScore) {

		int32_t j = 0;
		for (int32_t i = 0; i < group.countStudents; i++) {
			if ((group.students[i].averageScore - minimalAverageScore) > 0) {
				studentsWithScholarship[j] = group.students[i];
				j++;
			}
		}
	}

	void sortStudentsWithScholarShip(Student* studentsWithScholarship, const int32_t& countPassed, const double& minimalAverageScore) {
		//selection sort
		for (int32_t i = 0; i < countPassed - 1; i++)
		{
			int32_t minIndex = i;

			for (int32_t j = i; j < countPassed; j++)
			{
				if ((studentsWithScholarship[j].averageScore - studentsWithScholarship[minIndex].averageScore) < 0) {
					minIndex = j;
				}
			}

			if (minIndex != i)
			{
				swap(studentsWithScholarship[i], studentsWithScholarship[minIndex]);
			}
		}

	}

	void printStudents(const Group& group, const double& minimalAverageScore) {
		int32_t countPassed = countStudentsWithScholarShip(group, minimalAverageScore);

		Student* studentsWithScholarship = new Student[countPassed];
		getStudentsWithScholarship(studentsWithScholarship, group, minimalAverageScore);

		sortStudentsWithScholarShip(studentsWithScholarship, countPassed, minimalAverageScore);

		for (int32_t i = 0; i < countPassed; i++) {
			cout << studentsWithScholarship[i].name << " - " << studentsWithScholarship[i].averageScore << std::endl;
		}

		delete[] studentsWithScholarship;
	}
}
//main task8
/*using namespace Groups;
Group group;

//the user should enter the count of the students in the group and name of student and average score for each student
readGroup(group);

cout << countStudentsWithScholarShip(group, 3);
cout << " students with scholarship: " << std::endl;
printStudents(group, 3.5);*/

//task2 OOP_sem01
namespace RationalNumbers {
	struct Rational {
		//a rational number is a fraction p/q (q!-0)
		int32_t p, q;
	};

	bool isRationalNumberValid(const Rational& num) {
		if (num.q != 0) {
			return true;
		}
		return false;
	}

	void printRationalNumber(const Rational& num) {
		double tempP = num.p, tempQ = num.q;
		if (isRationalNumberValid(num)) {
			cout << (tempP / tempQ);
		}
	}

	bool isInteger(const Rational& num) {
		if (num.p % num.q == 0) {
			return true;
		}
		return false;
	}

	Rational addingNumbers(const Rational& num1, const Rational& num2) {
		Rational sum;
		sum.p = ((num1.p * num2.q) + (num2.p * num1.q));
		sum.q = num1.q * num2.q;

		return sum;
	}

	Rational subtracingNumbers(const Rational& num1, const Rational& num2) {
		Rational subtraction;
		subtraction.p = ((num1.p * num2.q) - (num2.p * num1.q));
		subtraction.q = num1.q * num2.q;

		return subtraction;
	}

	Rational multiplyingNumbers(const Rational& num1, const Rational& num2) {
		Rational product;
		product.p = num1.p * num2.p;
		product.q = num1.q * num2.q;

		return product;
	}

	Rational divisionOfNumbers(const Rational& num1, const Rational& num2) {
		Rational product;
		product.p = num1.p * num2.q;
		product.q = num1.q * num2.p;

		return product;
	}

}


int main()
{
	RationalNumbers::Rational n = { 4,8 };
	cout<<RationalNumbers::isRationalNumberValid(n)<<std::endl;
	RationalNumbers::printRationalNumber(n);
	
}