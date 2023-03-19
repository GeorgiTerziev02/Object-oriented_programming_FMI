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

class Teacher {
private:
    char name[MAX_NAME_LENGTH + 1];
    int age;
    int yearsOfExperience;

    bool isNameValid(char* nameToValidate) const {

        return nameToValidate != nullptr && strLength(nameToValidate) <= MAX_NAME_LENGTH;
    }

    bool isAgeValid(int ageToValidate) const {

        return ageToValidate >= 0;
    }

    bool areYearsOfExperienceValid(int yearsOfExperienceToValidate) const {

        return yearsOfExperienceToValidate >= 0 && yearsOfExperienceToValidate < this->age;
    }

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

    void setName(char* newName) {
        if(!isNameValid(newName)) {
            return;
        }

        strCopy(this->name, newName);
    }

    void setAge(int newAge) {
        if(!isAgeValid(newAge)) {
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
