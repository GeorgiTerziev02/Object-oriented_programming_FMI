#include "Farm.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <utility>
#include "AnimalFactory.h"

namespace {
    const int DEFAULT_CAPACITY = 8;
}

void Farm::resize() {
    Animal** newCollection = new Animal * [capacity *= 2];
    for (size_t i = 0; i < count; i++) {
        newCollection[i] = animals[i]; // we do not clone!
    }

    delete[] animals;
    animals = newCollection;
}
Farm::Farm() : count(0), capacity(DEFAULT_CAPACITY) {
    animals = new Animal * [capacity];
}

Farm::Farm(const Farm& other) {
    copyFrom(other);
}

Farm::Farm(Farm&& other) noexcept {
    moveFrom(std::move(other));
}

Farm& Farm::operator=(const Farm& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Farm& Farm::operator=(Farm&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Farm::~Farm() {
    free();
}

void Farm::addAnimal(AnimalType type) {
    if (count == capacity) {
        resize();
    }

    animals[count++] = animalFactory(type);
}

AnimalType Farm::getAnimalTypeAtIndex(size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Invalid index");
    }

    return animals[index]->getType();
}

void Farm::roarAll() const {
    for (size_t i = 0; i < count; i++) {
        animals[i]->roar();
    }
}

void Farm::free() {
    for (size_t i = 0; i < count; i++) {
        delete animals[i];
    }
    delete[] animals;
}

void Farm::copyFrom(const Farm& other) {
    count = other.count;
    capacity = other.capacity;
    animals = new Animal * [capacity];

    for (size_t i = 0; i < count; i++) {
        animals[i] = other.animals[i]->clone();
    }
}

void Farm::moveFrom(Farm&& other) {
    animals = other.animals;
    capacity = other.capacity;
    count = other.count;

    other.animals = nullptr;
    other.count = other.capacity = 0;
}
