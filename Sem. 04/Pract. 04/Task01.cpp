#include <iostream>

const int MAX_NAME_LENGTH = 128;

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

class Teacher {
private:
    char name[MAX_NAME_LENGTH + 1];
    int age;
    int yearsOfExperience;

public:

    Teacher() {
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

    bool setName(char* newName) {
        if(!isValidString(newName, MAX_NAME_LENGTH)) {
            return false;
        }

        strCopy(this->name, newName);

        return true;
    }

    bool setAge(int newAge) {
        if(!isNonNegativeNumber(newAge)) {
            return false;
        }

        this->age = newAge;

        return true;
    }

    bool setYearsOfExperience(int newYearsOfExperience) {
        if(!isNonNegativeNumber(newYearsOfExperience) || newYearsOfExperience > this->age) {
            return false;
        }

        this->yearsOfExperience = newYearsOfExperience;

        return true;
    }

    void print() const{
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Age: " << getAge() << std::endl;
        std::cout << "Years of experience: " << getYearsOfExperience() << std::endl;
        std::cout << "---" << std::endl;
    }

    ~Teacher() = default;

};

int main()
{
    char name[MAX_NAME_LENGTH + 1] = {};
    int age = 0;
    int yearsOfExperience = 0;

    std::cout << "Input name of teacher:";
    std::cin.getline(name, MAX_NAME_LENGTH + 1);

    std::cout << "Input age of teacher:";
    std::cin >> age;

    std::cout << "Input years of experience of teacher:";
    std::cin >> yearsOfExperience;

    Teacher person(name, age, yearsOfExperience);

    person.print();

    std::cout << "Input new name of teacher:";
    std::cin.ignore();
    std::cin.getline(name, MAX_NAME_LENGTH + 1);

    person.setName(name);

    person.print();

    return 0;
}
