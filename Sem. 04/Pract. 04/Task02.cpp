#include <iostream>
#include <fstream>

const char* EXAM_FILE = "exam.bin";
const char* ERROR_MESSAGE = "Error";

const int MAX_NAME_LENGTH = 128;
const int MAX_PROBLEM_LENGTH = 1024;

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

class Task {
private:
    char name[MAX_NAME_LENGTH + 1];
    char problem[MAX_PROBLEM_LENGTH + 1];
    int points;

    bool isNameValid(char* nameToValidate) const {

        return nameToValidate != nullptr && strLength(nameToValidate) <= MAX_NAME_LENGTH;
    }

    bool isProblemValid(char* problemToValidate) const {

        return problemToValidate != nullptr && strLength(problemToValidate) <= MAX_PROBLEM_LENGTH;
    }

    bool arePointsValid(int pointsToValidate) const {

        return pointsToValidate >= 0;
    }

public:

    Task() {
        this->points = 0;
    }

    Task(char* name, char* problem, int points) {
        setName(name);
        setProblem(problem);
        setPoints(points);
    }

    void setName(char* newName) {
        if(!isNameValid(newName)){
            return;
        }

        strCopy(this->name, newName);
    }

    void setProblem(char* newProblem) {
        if(!isProblemValid(newProblem)) {
            return;
        }

        strCopy(this->problem, newProblem);
    }

    void setPoints(int newPoints) {
        if(!arePointsValid(newPoints)) {
            return;
        }

        this->points = newPoints;
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

    void writeTaskToFile(std::ofstream& out, const char* fileName, char* newName, char* newProblem, int newPoints) const{
        int newNameLength = strLength(newName) + 1;
        int newProblemLength = strLength(newProblem) + 1;

        out.write((const char*) &newNameLength, sizeof(int));
        out.write((const char*) newName, newNameLength);
        out.write((const char*) &newProblemLength, sizeof(int));
        out.write((const char*) newProblem, newProblemLength);
        out.write((const char*) &newPoints, sizeof(int));
    }

    void readTaskFromFile(std::ifstream& in, const char* fileName) {
        int nameLength = 0;
        int problemLength = 0;

        in.read((char*) &nameLength, sizeof(int));

        char* newName = new char[nameLength];

        in.read(newName, nameLength);
        in.read((char*) &problemLength, sizeof(int));

        char* newProblem = new char[problemLength];

        in.read(newProblem, problemLength);
        in.read((char*) &this->points, sizeof(int));

        strCopy(this->name, newName);
        strCopy(this->problem, newProblem);
    }

    void printTask() const{
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Problem: " << this->problem << std::endl;
        std::cout << "Points: " << this->points << std::endl;
        std::cout << "---" << std::endl;
    }

};

class Exam {
private:
    int arraySize;
    int minPoints;
    Task* taskArray;

    bool isArraySizeValid(int arraySizeToValidate) const {

        return arraySizeToValidate >= 0;
    }

    bool areMinPointsValid(int minPointsToValidate) const {

        return minPointsToValidate >= 0;
    }

    bool isTaskArrayValid(Task* taskArrayToValidate) const {

        return taskArrayToValidate != nullptr;
    }

public:

    Exam() {
        this->arraySize = 0;
        this->minPoints = 0;
        this->taskArray = nullptr;
    }

    Exam(Task* taskArray, int arraySize, int minPoints) {
        writeExamToFile(taskArray, arraySize);
        changeMinPoints(minPoints);
    }

    void writeExamToFile(Task* newTaskArray, int newArraySize) const {
        if(!isTaskArrayValid(newTaskArray) || !isArraySizeValid(newArraySize)) {
            return;
        }

        char name[MAX_NAME_LENGTH + 1] = {};
        char problem[MAX_PROBLEM_LENGTH + 1] = {};

        std::ofstream out(EXAM_FILE, std::ios::binary);

        if(!out.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        out.write((const char*) &newArraySize, sizeof(int));

        for(int i = 0; i < newArraySize; ++i) {
            int points = newTaskArray[i].getPoints();

            strCopy(name, newTaskArray[i].getName());

            strCopy(problem, newTaskArray[i].getProblem());

            newTaskArray[i].writeTaskToFile(out, EXAM_FILE, name, problem, points);
        }

        out.close();
    }

    void readExamFromFile() {
        std::ifstream in(EXAM_FILE, std::ios::binary);

        if(!in.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        if(this->taskArray != nullptr){
            delete[] this->taskArray;
        }

        in.read((char*) &this->arraySize, sizeof(int));

        this->taskArray = new Task[this->arraySize];

        for(int i = 0; i < this->arraySize; ++i) {
            this->taskArray[i].readTaskFromFile(in, EXAM_FILE);
        }

        in.close();
    }

    void changeMinPoints(int newMinPoints) {
        if(!areMinPointsValid(newMinPoints)) {
            return;
        }

        this->minPoints = newMinPoints;
    }

    int getMaxPoints() const {
        int maxPoints = 0;

        for(int i = 0; i < this->arraySize; ++i) {
            maxPoints += taskArray[i].getPoints();
        }

        return maxPoints;
    }

    void printExam() const{
        for(int i = 0; i < this->arraySize; ++i){
            taskArray[i].printTask();
        }

        std::cout << "Max points: " << this->getMaxPoints();
    }

};

int main() {
    int arraySize = 0;
    int minPoints = 0;
    char name[MAX_NAME_LENGTH + 1] = {};
    char problem[MAX_PROBLEM_LENGTH + 1] = {};
    int taskPoints = 0;

    std::cout << "Input number of tasks:";
    std::cin >> arraySize;

    std::cout << "Input minimum points:";
    std::cin >> minPoints;

    Task* taskArray = new Task[arraySize];

    for(int i = 0; i < arraySize; ++i){
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

    Exam testExam(taskArray, arraySize, minPoints);

    Exam examFromFile;

    examFromFile.readExamFromFile();

    examFromFile.printExam();

    delete[] taskArray;

    return 0;
}
