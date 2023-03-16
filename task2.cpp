#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
const int MAX_TASKS = 5;
const int MAX = 0;
class Task {
private:
    char* name;
    int nameLength;
    char* requirement;
    int requirementLength;
    int points;

public:
    Task() = default;
    Task(const char* name, int nameLength ,const  char* requirement,int requirementLength,int point) {
        this->nameLength = nameLength;
        this->name = new char[nameLength + 1];
        strcpy(this->name, name);
        this->requirementLength = requirementLength;
        this->requirement = new char[requirementLength + 1];
        strcpy(this->requirement, requirement);
        this->points=points;
    }

    const char* getName() const {
        return this->name;
    }

    int  getNameLength() const {
        return this->nameLength;
    }

    const char* getRequirement() const {
        return this->requirement;
    }

    int  getRequirementLength() const {
        return this->requirementLength;
    }

    int  getPoints() const {
        return this->points;
    }

    void setName(char* name, int nameLength) {
        if (name != nullptr) {
            delete[] this->name;
        }
        this->nameLength = nameLength;
        this->name = new char[nameLength + 1];
        strcpy(this->name, name);
    }
    
    void setRequirement(char* requirement, int requirementLength) {
        if (requirement != nullptr) {
            delete[] this->requirement;
        }
        this->requirementLength = requirementLength;
        this->requirement = new char[requirementLength + 1];
        strcpy(this->name, name);
    }

    void setPoints(int points) {
        this->points = points;
    }

    void writeTaskToFile(std::ofstream& out) const {
        if (!out.is_open()) {
            return;
        }
        out.write((const char*)this->getNameLength(), sizeof(this->getNameLength()));
        out.write((const char*)this->getName(), this->getNameLength());
        out.write((const char*)this->getRequirementLength(), sizeof(this->getRequirementLength()));
        out.write((const char*)this->getRequirement(), this->getRequirementLength());
        out.write((const char*)this->getPoints(),this->getPoints());
    }

    void readTaskToFile(std::ifstream& inputFile) const{
        if (!inputFile.is_open()) {
            return;
        }
        inputFile.read((char*)this->getNameLength(), sizeof(getNameLength()));
        inputFile.read((char*)this->getName(), this->getNameLength());
        inputFile.read((char*)this->getRequirementLength(), sizeof(getRequirementLength()));
        inputFile.read((char*)this->getRequirement(), this->getRequirementLength());
        inputFile.read((char*)this->getPoints(), sizeof(this->getPoints()));
    }

    ~Task()
    {
        delete[] this->name;
        delete[] this->requirement;
    }

};

struct Exam {
private:
    Task tasks[MAX_TASKS];
    int numberOfTasks;
    int minPoints;
public:

    void writeToFile(const char* fileName)const {
        std::ofstream out(fileName, std::ios::binary);
        if (!out.is_open()) {
            return;
        }
        for (int i = 0; i < this->numberOfTasks; i++) {
            this->tasks[i].writeTaskToFile(out);
        }
        out.close();
    }

    void readFromFile(const char* fileName) {
        std::ifstream inputFile(fileName, std::ios::binary);
        if (!inputFile.is_open()) {
            return;
        }
        for (int i = 0; i < this->numberOfTasks; i++) {
            this->tasks[i].readTaskToFile(inputFile);
        }
        inputFile.close();
    }

    void newMin(int newMinPoints) {
        this->minPoints = newMinPoints;
    }
    
    int getMax() {
        int max = MAX;
        for (int i = 0; i < numberOfTasks; i++) {
            if (this->tasks[i].getPoints() > MAX) {
                max = this->tasks[i].getPoints();
            }
        }
        return max;
    }
};

int main()
{

}