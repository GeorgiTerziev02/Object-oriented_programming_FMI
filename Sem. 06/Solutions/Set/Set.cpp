#include "Set.h"
#include <iostream>

const short BITS[] = { 128, 64, 32, 16, 8, 4, 2, 1};
const short MAX_BITS = 8;
const short ALL_ONES = 255;

void Set::resize(size_t number) {
	size_t newSize = number / MAX_BITS + 1;
	unsigned char* temp = new unsigned char[newSize] {};
	if (numbers != nullptr) {
		memcpy(temp, numbers, size);
		delete[] numbers;
	}
	size = newSize;
	numbers = temp;
}

Set::Set() {
	numbers = nullptr;
}

Set::Set(const Set& other) {
	copyFrom(other);
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Set::~Set() {
	free();
}

void Set::addNumber(size_t number) {
	if (number / MAX_BITS >= size) {
		resize(number);
	}

	numbers[number / MAX_BITS] |= BITS[number % MAX_BITS];
}

void Set::removeNumber(size_t number) {
	if (number / MAX_BITS >= size) {
		return;
	}

	numbers[number / MAX_BITS] &= (ALL_ONES - BITS[number % MAX_BITS]);
}

bool Set::containsNumber(size_t number) const {
	if (number / MAX_BITS >= size) {
		return false;
	}

	return (numbers[number / MAX_BITS] & BITS[number % MAX_BITS]) != 0;
}

Set Set::merge(const Set& other) const {
    // TODO:
    return *this;
}

Set Set::intersect(const Set& other) const {
    // TODO:
    return *this;
}

void Set::print() const {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < MAX_BITS; j++) {
			if ((numbers[i] & BITS[j]) != 0) { // TODO: extract function
				std::cout << i * MAX_BITS + j << " ";
			}
		}
	}
}

void Set::printBits() const {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < MAX_BITS; j++) {
			std::cout << ((numbers[i] & BITS[j]) != 0);
		}
	}
}

void Set::free() {
	delete[] numbers;
	size = 0;
}

void Set::copyFrom(const Set& other) {
	size = other.size;
	numbers = new unsigned char[size];
	memcpy(numbers, other.numbers, size);
}