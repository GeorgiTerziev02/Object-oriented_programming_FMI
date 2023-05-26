#include "VectorRestaurant.h"
#include <exception>
#include <cmath>

namespace {
	const short INITIAL_CAPACITY = 4;
	const short RESIZE_COEF = 2;
}

VectorOfStrings::VectorOfStrings() : VectorOfStrings(INITIAL_CAPACITY) { }

VectorOfStrings::VectorOfStrings(size_t capacity) : capacity(capacity) {
	data = new MyString[capacity];
}

VectorOfStrings::VectorOfStrings(const VectorOfStrings& other) {
	copyFrom(other);
}

VectorOfStrings& VectorOfStrings::operator=(const VectorOfStrings& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

VectorOfStrings::~VectorOfStrings() {
	free();
}

void VectorOfStrings::assertIndex(size_t index) const {
	if (index >= size) {
		throw std::exception("Out of range");
	}
}

void VectorOfStrings::upsizeIfNeeded() {
	if (size == capacity) {
		resize(capacity * RESIZE_COEF);
	}
}

void VectorOfStrings::downsizeIfNeeded() {
	if (size * RESIZE_COEF * RESIZE_COEF <= capacity) {
		resize(capacity / RESIZE_COEF);
	}
}

void VectorOfStrings::resize(size_t newCapacity) {
	capacity = newCapacity;
	MyString* temp = new MyString[capacity];

	
	if (size > newCapacity) {
		size = newCapacity;
	}

	for (size_t i = 0; i < size; i++) {
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

size_t VectorOfStrings::getSize() const {
	return size;
}

size_t VectorOfStrings::getCapacity() const {
	return capacity;
}

void VectorOfStrings::pushBack(const MyString& element) {
	upsizeIfNeeded();
	data[size++] = element;
}

void VectorOfStrings::pushAt(const MyString& element, size_t index) {
	assertIndex(index);
	upsizeIfNeeded();

	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}

	data[index] = element;
	size++;
}

MyString VectorOfStrings::popBack() {
	if (empty()) {
		throw std::exception("Vector is empty");
	}

	downsizeIfNeeded();

	return data[size--];
}

MyString VectorOfStrings::popAt(size_t index) {
	assertIndex(index);
	
	downsizeIfNeeded();

	MyString temp = data[index];
	size--;
	for (size_t i = index; i < size; i++) {
		data[i] = data[i + 1];
	}

	return data[index];
}

bool VectorOfStrings::empty() const {
	return size == 0;
}

void VectorOfStrings::clear() {
	size = 0;
}

void VectorOfStrings::shrinkToFit() {
	resize(size);
}

MyString& VectorOfStrings::operator[](size_t index) {
	assertIndex(index);
	return data[index];
}

const MyString& VectorOfStrings::operator[](size_t index) const {
	assertIndex(index);
	return data[index];
}

void VectorOfStrings::copyFrom(const VectorOfStrings& other) {
	size = other.size;
	capacity = other.capacity;
	data = new MyString[capacity];

	for (size_t i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
}

void VectorOfStrings::free() {
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}