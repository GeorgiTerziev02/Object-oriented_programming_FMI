#include <iostream>

const int MAX_NAME_LENGTH = 128;

int strLength(const char* str) {
    int length = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        length++;
    }

    return length;
}

void strCopy(char* destination, const char* origin) {
    int length = strLength(origin) + 1;

    for (int i = 0; i < length; ++i) {
        destination[i] = origin[i];
    }
}

class Teacher {
private:
    char* name;
    int age;
    int yearsOfExperience;

    void setName(char* newName) {
        if(newName == nullptr) {
            return;
        }

        int newNameLength = strLength(newName) + 1;

        this->name = new char[newNameLength];

        strCopy(this->name, newName);
    }

public:

    Teacher() {
        this->name = nullptr;
        this->age = 0;
        this->yearsOfExperience = 0;
    }

    Teacher(char* name, int age, int yearsOfExperience) {
        setName(name);
        setAge(age);
        setYearsOfExperience(yearsOfExperience);
    }

    const char* getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getYearsOfExperience() const {
        return yearsOfExperience;
    }

    void setNewName(char* newName) {
        if(this->name != nullptr){
            delete[] this->name;
        }

        setName(newName);
    }

    void setAge(int newAge) {
        if(newAge < 0) {
            return;
        }

        this->age = newAge;
    }

    void setYearsOfExperience(int newYearsOfExperience) {
        if(newYearsOfExperience < 0 || newYearsOfExperience > this->age) {
            return;
        }

        this->yearsOfExperience = newYearsOfExperience;
    }

    void print() const{
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Age: " << getAge() << std::endl;
        std::cout << "Years of experience: " << getYearsOfExperience() << std::endl;
        std::cout << "---" << std::endl;
    }

    ~Teacher() {
        delete[] this->name;
    }

};

int main()
{
    char name[MAX_NAME_LENGTH] = {};
    int age = 0;
    int yearsOfExperience = 0;

    std::cout << "Input name of teacher:";
    std::cin.getline(name, MAX_NAME_LENGTH);

    std::cout << "Input age of teacher:";
    std::cin >> age;

    std::cout << "Input years of experience of teacher:";
    std::cin >> yearsOfExperience;

    Teacher person(name, age, yearsOfExperience);

    person.print();

    std::cout << "Input new name of teacher:";
    std::cin.ignore();
    std::cin.getline(name, MAX_NAME_LENGTH);

    person.setNewName(name);

    person.print();

    return 0;
}
