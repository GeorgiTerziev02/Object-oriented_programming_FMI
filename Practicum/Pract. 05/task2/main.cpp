#include "Exam.h"
#include "Task.h"

int main() {
    Exam exam;

    Task t1("What is the result of 2+2? \n a) 4 \n b) 100 \n b) 31 \n b) 2 \n", 'a', 5, "pass1");

    exam.addTask(t1);
    exam.writeToFile("exam.bin");

    Exam examFromFile;

    examFromFile.readFromFile("exam.bin");
    examFromFile.conductExam();

    return 0;
}

