#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const unsigned short NAME_MAX_SIZE = 100;
const unsigned short FN_MAX_SIZE = 10;
double groupAverageGrade = 0;

struct Student {
    char name[NAME_MAX_SIZE];
    char fn[FN_MAX_SIZE];
    double grade;
};

void readStudents(const unsigned int studentsCount, Student*& students) {
    for (unsigned int i = 0; i < studentsCount; i++) {
        cin >> students[i].name >> students[i].fn >> students[i].grade;
        groupAverageGrade += students->grade;
    }

    groupAverageGrade /= studentsCount;
}

unsigned int chechStudentShip(const double studentShip, const Student* students, const unsigned int studentsCount) {
    unsigned int studentsWithShip = 0;
    for (unsigned int i = 0; i < studentsCount; i++) {
        if (students[i].grade >= studentShip) {
            studentsWithShip++;
        }
    }

    return studentsWithShip;
}

void fillSortedStudentsWithShips(const double studentShip, const unsigned int studentsCount, Student* sortedStudentsWithShips, const Student* students) {
    unsigned int k = 0;
    for (unsigned int i = 0; i < studentsCount; i++) {
        if (students[i].grade >= studentShip) {
            sortedStudentsWithShips[k++] = students[i];
        }
    }
}

void swapStudents(Student*& sortedStudentsWithShips, const unsigned int j) {
    Student tempStudent = sortedStudentsWithShips[j];
    sortedStudentsWithShips[j] = sortedStudentsWithShips[j + 1];
    sortedStudentsWithShips[j + 1] = tempStudent;
}

void sortStudents(const unsigned int studentsCount, Student*& sortedStudents) {
    for (unsigned int i = 0; i < studentsCount - 1; i++) {
        bool swapped = false;

        for (unsigned int j = 0; j < studentsCount - i - 1; j++) {
            if ((sortedStudents[j].grade - sortedStudents[j + 1].grade) > 0) {
                swapStudents(sortedStudents, j);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void printStudents(Student*& students, const unsigned int studentsCount) {
    for (unsigned int i = 0; i < studentsCount; i++) {
        cout << "Name: " << students[i].name << "; FN: " << *students[i].fn << "; Grade: " << students[i].grade << endl;
    }
}

bool isStudentInGroup(const Student* students, const unsigned int studentsCount, const char* fn) {
    for (unsigned int i = 0; i < studentsCount; i++) {
        if (*students[i].fn == *fn) {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Enter students count: ";
    unsigned int studentsCount;
    cin >> studentsCount;
    Student* students = new Student[studentsCount];
    readStudents(studentsCount, students);
    printStudents(students, studentsCount);
    cout << endl;

    cout << "Enter students ship: ";
    double studentShip;
    cin >> studentShip;
    unsigned int studentsWithShipsCount = chechStudentShip(studentShip, students, studentsCount);
    cout << "Students with ships count: " << studentsWithShipsCount << endl;
    cout << endl;

    Student* sortedStudentsWithShips = new Student[studentsWithShipsCount];
    fillSortedStudentsWithShips(studentShip, studentsWithShipsCount, sortedStudentsWithShips, students);
    sortStudents(studentsWithShipsCount, sortedStudentsWithShips);
    printStudents(sortedStudentsWithShips, studentsWithShipsCount);
    cout << endl;

    cout << "Enter student FN: ";
    sortStudents(studentsCount, students);
    char fNum[FN_MAX_SIZE];
    cin >> fNum;
    cout << (isStudentInGroup(students, studentsCount, fNum) ? "There is student with this FN" : "There isn't student with this FN");
    cout << endl;

    delete[] students;
    delete[] sortedStudentsWithShips;
}