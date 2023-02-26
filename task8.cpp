#include <iostream>
using namespace std;
struct Students {
	char name[30];
	double grades[30];
	int average;
};
void swap(Students& a, Students& b) {
	Students temp = a;
	a = b;
	b = temp;
}
void selectionSort(Students* group, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < length; j++) {
			if (group[minIndex].average > group[j].average) {
				minIndex = j;
			}
		}
		if (minIndex != i)
			swap(group[i], group[minIndex]);
	}
}
void createStudent(Students& student, const char(&name)[30], const int& gradesNum) {
	int j=0;
	double sum = 0;
	int len1 = sizeof(name) / sizeof(char);
	while (name[j] != '\0') {
		student.name[j] = name[j];
		j++;
	}
	int* grades = new int[gradesNum];
	for (int i = 0; i < gradesNum; i++) {
		cout << "Grade:";
		cin >> student.grades[i];
		sum += student.grades[i];
	}
	student.average = sum / gradesNum;
}
void createGroup(Students* group, int& n) {
	char name[30];
	int gradesNum;
	double average = 0;
	for (int i = 0; i < n; i++) {
		cout << "Enter name of the student:" << endl;
		cin.getline(name, 30);
		cout << "Enter number of grades this student has: " << endl;
		cin >> gradesNum;
		createStudent(group[i], name, gradesNum);
		cin.ignore();
	}
}
int scholarship(Students* group, double& min,int& n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (group[i].average-min>0.00001) {
			count++;
		}
	}
	return count;
}
void sortScholarships(Students* group, double& min,int& n) {
	int count = scholarship(group, min,n),j=0;
	Students* scholars = new Students[count];
	for (int i = 0; i < n; i++) {
		if (group[i].average-min>0.00001) {
			scholars[j] = group[i];
			j++;
		}
	}
	selectionSort(scholars, count);
	for (int i = 0; i < count; i++) {
		cout << "Name: " << scholars[i].name;
		cout << endl;
		cout << "Grades: " << scholars[i].grades;
		cout << endl;
		cout << "Average score: " << scholars[i].average;
		cout << endl;
	}
}
int main() {
	int n;
	double min;
	cout << "Enter number of students in group: ";
	cin >> n;
	cin.ignore();
	Students* group=new Students[n];
	createGroup(group, n);
	cout << "What is the minimum average score for scholarship: ";
	cin >> min;
	cout<<"Number of students who get scholarships: " << scholarship(group, min,n);
	sortScholarships(group, min, n);
}
