#pragma once

const short MAX_NAME_LENGTH = 30;

class Teacher {
private:
    char name[MAX_NAME_LENGTH + 1];
    size_t age;
    size_t experience;
public:
    Teacher(const char* name, size_t age, size_t experience);

    const char* getName() const;
    size_t getAge() const;
    size_t getExperience() const;

    bool setName(const char* name);
    bool setAge(size_t age);
    bool setExperience(size_t experience);
};