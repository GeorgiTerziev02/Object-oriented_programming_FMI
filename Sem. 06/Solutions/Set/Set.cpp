#include "Set.h"
#include <iostream>

const unsigned char BITS[] = { 128, 64, 32, 16, 8, 4, 2, 1 };
const unsigned char MAX_BITS = 8;
const unsigned char ALL_ONES = 255;
const short MAX_ALLOWED_NUMBER = 1000;

bool isBitSet(unsigned char byte, size_t bitIndex) {
	return (byte & BITS[bitIndex]) != 0;
}

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
	if(number > MAX_ALLOWED_NUMBER) {
		return;
	}

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

	return isBitSet(numbers[number / MAX_BITS], number % MAX_BITS);
}

Set Set::merge(const Set& other) const {
	Set result = size >= other.size ? *this : other;
	const Set& shorterSet = size >= other.size ? other : *this;

	for (size_t i = 0; i < shorterSet.size; i++) {
		result.numbers[i] |= shorterSet.numbers[i];
	}

	return result;
}

Set Set::intersect(const Set& other) const {
	Set result = size >= other.size ? other : *this;
	const Set& longerSet = size >= other.size ? *this : other;

	for (size_t i = 0; i < result.size; i++) {
		result.numbers[i] &= longerSet.numbers[i];
	}

	return result;
}

void Set::print() const {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < MAX_BITS; j++) {
			if (isBitSet(numbers[i], j)) {
				std::cout << i * MAX_BITS + j << " ";
			}
		}
	}
}

void Set::printBits() const {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < MAX_BITS; j++) {
			std::cout << isBitSet(numbers[i], j);
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
