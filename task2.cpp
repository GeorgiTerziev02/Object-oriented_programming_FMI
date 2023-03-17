#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)

char* strCopy(char* destination, const char* source) {
    if (destination == nullptr) {
        return NULL;
    }
    char* ptr = destination;
    while(*source!='\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

size_t strLen(const char* s) {
    size_t count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

const int MAX_TASKS = 5;

class Task {
private:
    char* name;
    size_t nameLength;
    char* requirement;
    size_t requirementLength;
    int points;

public:
    Task() = default;
    Task(const char* name,const  char* requirement,int point) {
        this->nameLength = strLen(name);
        this->name = new char[this->nameLength + 1];
        strCopy(this->name, name);
        this->requirementLength = strLen(requirement);
        this->requirement = new char[this->requirementLength + 1];
        strCopy(this->requirement, requirement);
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

    void setName(const char* name) {
        if (name != nullptr) {
            delete[] this->name;
        }
        this->nameLength = strLen(name);
        this->name = new char[this->nameLength + 1];
        strCopy(this->name, name);
    }
    
    void setRequirement(char* requirement) {
        if (requirement != nullptr) {
            delete[] this->requirement;
        }
        this->requirementLength = strLen(requirement);
        this->requirement = new char[this->requirementLength + 1];
        strCopy(this->name, name);
    }

    void setPoints(int points) {
        this->points = points;
    }

    void writeTaskToFile(std::ofstream& out) const {
        if (!out.is_open()) {
            return;
        }
        out.write((const char*)this->nameLength, sizeof(this->nameLength));
        out.write((const char*)this->name, this->nameLength);
        out.write((const char*)this->requirementLength, sizeof(this->requirementLength));
        out.write((const char*)this->requirement, this->requirementLength);
        out.write((const char*)this->points,sizeof(this->points));
    }

    void readTaskToFile(std::ifstream& inputFile) const{
        if (!inputFile.is_open()) {
            return;
        }

        if (this->name != nullptr) {
            delete[] this->name;
        }

        if (this->requirement != nullptr) {
            delete[] this->requirement;
        }



        inputFile.read((char*)this->nameLength, sizeof(this->nameLength));
        inputFile.read((char*)this->name, this->nameLength);
        inputFile.read((char*)this->requirementLength, sizeof(this->requirementLength));
        inputFile.read((char*)this->requirement, this->requirementLength);
        inputFile.read((char*)this->points, sizeof(this->points));
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

        out.write((const char*)this->numberOfTasks, sizeof(this->numberOfTasks));
        out.write((const char*)this->minPoints, sizeof(this->minPoints));

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

        inputFile.read((char*)this->numberOfTasks, sizeof(this->numberOfTasks));
        inputFile.read((char*)this->minPoints, sizeof(this->minPoints));

        for (int i = 0; i < this->numberOfTasks; i++) {
            this->tasks[i].readTaskToFile(inputFile);
        }
        inputFile.close();
    }

    void newMin(int newMinPoints) {
        this->minPoints = newMinPoints;
    }
    
    int getMax() const {
        int max = 0;
        for (int i = 0; i < numberOfTasks; i++) {
            if (this->tasks[i].getPoints() > max) {
                max = this->tasks[i].getPoints();
            }
        }
        return max;
    }
};

int main()
{

}