#include "Person.h"
#include <cstring>
#include <iostream>

#pragma warning(disable : 4996)

void Person::copyName(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::Person(const char* name, int age) : age(age) {
    if (!name) {
        copyName("");
    }
    else {
        copyName(name);
    }
}

Person::Person(const Person& other) {
    copyFrom(other);
}

Person::Person(Person&& other) noexcept {
    moveFrom(std::move(other));
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Person& Person::operator=(Person&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Person::~Person() {
    free();
}

const char* Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::print() const {
    std::cout << "Name: " << name << " Age: " << age;
}

void Person::copyFrom(const Person& other) {
    age = other.age;
    copyName(other.name);
}

void Person::moveFrom(Person&& other) noexcept {
    name = other.name;
    age = other.age;

    other.age = 0;
    other.name = nullptr;
}

void Person::free() {
    delete[] name;
}
