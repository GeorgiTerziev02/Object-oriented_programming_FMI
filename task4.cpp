#include <iostream>
using namespace std;
struct Students {
    char name[30];
    unsigned int facNum;
};
void readStudent(Students& student, char(&name)[30], int& facNum,int& index) {
    index = 0;
    cout << "Enter student name:" << endl;
    cin.getline(name, 30);
    cout << "Enter faculty numbeer:" << endl;
    cin >> facNum;
    while (name[index] != '\0') {
        student.name[index] = name[index];
        index++;
    }
    student.facNum = facNum;
}
void printStudent(Students& student,int& index) {
    cout << "Name:";
    for(int j=0;j<index;j++) {
        cout << student.name[j];
    }
    cout << endl;
    cout << "Faculty number:" << student.facNum;
}
int main()
{
    char name[30];
    int facNum,index;
    Students student;
    readStudent(student, name, facNum,index);
    printStudent(student,index);
}