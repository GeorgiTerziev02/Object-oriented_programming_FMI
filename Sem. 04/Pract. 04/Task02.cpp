#include <iostream>
#include <fstream>

const char* EXAM_FILE = "exam.bin";
const char* ERROR_MESSAGE = "Error";

const int MAX_NAME_LENGTH = 128;
const int MAX_PROBLEM_LENGTH = 256;
const int NUMBER_OF_TASKS_IN_EXAM = 3;

int strLength(const char* str) {
    int index = 0;

    while(str[index] != '\0') {
        index++;
    }

    return index;
}

void strCopy(char* destination, const char* origin) {
    int index = 0;

    while(origin[index] != '\0') {
        destination[index] = origin[index];
        index++;
    }

    destination[index] = '\0';
}

bool isValidString(char* str, const int maxLength) {

    return str != nullptr && strLength(str) <= maxLength;
}

bool isNonNegativeNumber(int number) {

    return number >= 0;
}

class Task {
private:
    char name[MAX_NAME_LENGTH + 1];
    char problem[MAX_PROBLEM_LENGTH + 1];
    int points;

public:

    Task() {
        this->points = 0;
    }

    Task(char* name, char* problem, int points) {
        setName(name);
        setProblem(problem);
        setPoints(points);
    }

    bool setName(char* newName) {
        if(!isValidString(newName, MAX_NAME_LENGTH)){
            return false;
        }

        strCopy(this->name, newName);

        return true;
    }

    bool setProblem(char* newProblem) {
        if(!isValidString(newProblem, MAX_PROBLEM_LENGTH)) {
            return false;
        }

        strCopy(this->problem, newProblem);

        return true;
    }

    bool setPoints(int newPoints) {
        if(!isNonNegativeNumber(newPoints)) {
            return false;
        }

        this->points = newPoints;

        return true;
    }

    const char* getName() const{
        return name;
    }

    const char* getProblem() const{
        return problem;
    }

    int getPoints() const {
        return points;
    }

    bool writeTaskToFile(std::ofstream& out, const char* fileName, char* newName, char* newProblem, int newPoints) const {
        if(!isValidString(newName, MAX_NAME_LENGTH) || !isValidString(newProblem, MAX_PROBLEM_LENGTH) || !isNonNegativeNumber(newPoints)) {
            return false;
        }

        out.write((const char*) newName, MAX_NAME_LENGTH);
        out.write((const char*) newProblem, MAX_PROBLEM_LENGTH);
        out.write((const char*) &newPoints, sizeof(int));

        return true;
    }

    void readTaskFromFile(std::ifstream& in, const char* fileName) {

        in.read((char*) this->name, MAX_NAME_LENGTH);
        in.read((char*) this->problem, MAX_PROBLEM_LENGTH);
        in.read((char*) &this->points, sizeof(int));
    }

    void printTask() const{
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Problem: " << this->problem << std::endl;
        std::cout << "Points: " << this->points << std::endl;
        std::cout << "---" << std::endl;
    }

};

bool isValidTaskArray(Task* taskArrayToValidate) {

    return taskArrayToValidate != nullptr;
}

class Exam {
private:
    int minPoints;
    Task taskArray[NUMBER_OF_TASKS_IN_EXAM];

public:

    Exam() {
        this->minPoints = 0;
    }

    Exam(Task* taskArray, int minPoints) {
        writeExamToFile(taskArray);
        changeMinPoints(minPoints);
    }

    bool writeExamToFile(Task* newTaskArray) const {
        if(!isValidTaskArray(newTaskArray)) {
            return false;
        }

        char name[MAX_NAME_LENGTH + 1] = {};
        char problem[MAX_PROBLEM_LENGTH + 1] = {};

        std::ofstream out(EXAM_FILE, std::ios::binary);

        if(!out.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return false;
        }

        for(int i = 0; i < NUMBER_OF_TASKS_IN_EXAM; ++i) {
            int points = newTaskArray[i].getPoints();

            strCopy(name, newTaskArray[i].getName());

            strCopy(problem, newTaskArray[i].getProblem());

            newTaskArray[i].writeTaskToFile(out, EXAM_FILE, name, problem, points);
        }

        out.close();

        return true;
    }

    void readExamFromFile() {
        std::ifstream in(EXAM_FILE, std::ios::binary);

        if(!in.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        for(int i = 0; i < NUMBER_OF_TASKS_IN_EXAM; ++i) {
            this->taskArray[i].readTaskFromFile(in, EXAM_FILE);
        }

        in.close();
    }

    bool changeMinPoints(int newMinPoints) {
        if(!isNonNegativeNumber(newMinPoints) || newMinPoints > this->getMaxPoints()) {
            return false;
        }

        this->minPoints = newMinPoints;

        return true;
    }

    int getMaxPoints() const {
        int maxPoints = 0;

        for(int i = 0; i < NUMBER_OF_TASKS_IN_EXAM; ++i) {
            maxPoints += taskArray[i].getPoints();
        }

        return maxPoints;
    }

    void printExam() const{
        for(int i = 0; i < NUMBER_OF_TASKS_IN_EXAM; ++i){
            taskArray[i].printTask();
        }

        std::cout << "Min points: " << this->minPoints << std::endl;
        std::cout << "Max points: " << this->getMaxPoints() << std::endl;
    }

};

int main() {
    int minPoints = 0;
    char name[MAX_NAME_LENGTH + 1] = {};
    char problem[MAX_PROBLEM_LENGTH + 1] = {};
    int taskPoints = 0;

    std::cout << "Input minimum points:";
    std::cin >> minPoints;

    Task* taskArray = new Task[NUMBER_OF_TASKS_IN_EXAM];

    for(int i = 0; i < NUMBER_OF_TASKS_IN_EXAM; ++i){
        std::cin.ignore();
        std::cout << "Input task(" << i + 1 << ") name:";
        std::cin.getline(name, MAX_NAME_LENGTH + 1);

        std::cout << "Input task(" << i + 1 << ") problem:";
        std::cin.getline(problem, MAX_NAME_LENGTH + 1);

        std::cout << "Input task(" << i + 1 << ") points:";
        std::cin >> taskPoints;

        Task taskToAdd(name, problem, taskPoints);
        taskArray[i] = taskToAdd;
    }

    Exam testExam(taskArray, minPoints);

    Exam examFromFile;

    examFromFile.readExamFromFile();

    examFromFile.printExam();

    delete[] taskArray;

    return 0;
}
