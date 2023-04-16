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

Teacher::Teacher(const char *name, size_t age, size_t experience) {
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

size_t Teacher::getAge() const {
    return age;
}

size_t Teacher::getExperience() const {
    return experience;
}

bool Teacher::setName(const char *name) {
    if (!isNameValid(name)) {
        return false;
    }

    strcpy(this->name, name);
    return true;
}

bool Teacher::setAge(size_t age) {
    if(age < MIN_AGE || age > MAX_AGE) {
        return false;
    }

    this->age = age;
    return true;
}

bool Teacher::setExperience(size_t experience) {
    if(experience > MAX_EXPERIENCE) {
        return false;
    }

    this->experience = experience;
    return true;
}
