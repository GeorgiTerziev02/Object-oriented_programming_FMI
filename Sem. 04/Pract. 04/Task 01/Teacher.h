#pragma once

const short MAX_NAME_LENGTH = 30;

class Teacher {
private:
    char name[MAX_NAME_LENGTH + 1];
    unsigned age;
    unsigned experience;
public:
    Teacher(const char* name, unsigned age, unsigned experience);

    const char* getName() const;
    unsigned getAge() const;
    unsigned getExperience() const;

    void setName(const char* name);
    void setAge(unsigned age);
    void setExperience(unsigned experience);
};