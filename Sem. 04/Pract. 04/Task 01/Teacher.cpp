#include <Teacher.h>
#include <cstring>
#pragma warning(disable : 4996)

const short MIN_AGE = 18;
const short MAX_AGE = 100;
const short MAX_EXPERIENCE = 100;

bool isNameValid(const char *name) {
    if(name == nullptr) {
        return false;
    }
    size_t nameLength = strlen(name);
    return nameLength > 0 && nameLength <= MAX_NAME_LENGTH;
}

Teacher::Teacher(const char *name, unsigned age, unsigned experience) {
    this->name[0] = '\0';
    if (isNameValid(name)) {
        strcpy(this->name, name);
    }

    if(age < MIN_AGE || age > MAX_AGE) {
        age = MIN_AGE;
    }
    if(experience > MAX_EXPERIENCE) {
        experience = 0;
    }

    this->age = age;
    this->experience = experience;
}

const char *Teacher::getName() const {
    return name;
}

unsigned Teacher::getAge() const {
    return age;
}

unsigned Teacher::getExperience() const {
    return experience;
}

void Teacher::setName(const char *name) {
    if (!isNameValid(name)) {
        return;
    }

    strcpy(this->name, name);
}

void Teacher::setAge(unsigned age) {
    if(age < MIN_AGE || age > MAX_AGE) {
        return;
    }

    this->age = age;
}

void Teacher::setExperience(unsigned experience) {
    if(experience > MAX_EXPERIENCE) {
        return;
    }

    this->experience = experience;
}
