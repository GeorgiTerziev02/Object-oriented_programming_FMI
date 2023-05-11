#include "Vector.h"
#include <exception>
#include <cmath>

namespace {
	const short INITIAL_CAPACITY = 4;
	const short RESIZE_COEF = 2; // the most optimal is between 1.4 and 1.5
}

Vector::Vector() : Vector(INITIAL_CAPACITY) { }

Vector::Vector(size_t capacity) : capacity(capacity) {
	data = new Test[capacity];
}

Vector::Vector(const Vector& other) {
	copyFrom(other);
}

Vector::Vector(Vector&& other) {
	move(std::move(other));
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Vector& Vector::operator=(Vector&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

Vector::~Vector() {
	free();
}

void Vector::assertIndex(size_t index) const {
	if (index >= size) {
		throw std::exception("Out of range");
	}
}

void Vector::upsizeIfNeeded() {
	if (size == capacity) {
		resize(capacity * RESIZE_COEF);
	}
}

void Vector::downsizeIfNeeded() {
	if (size * RESIZE_COEF * RESIZE_COEF <= capacity) {
		resize(capacity / RESIZE_COEF);
	}
}

void Vector::resize(size_t newCapacity) {
	capacity = newCapacity;
	Test* temp = new Test[capacity];
	
	// Note: the std::vector allocates ONLY MORE than the current capacity
	if (size > newCapacity) {
		size = newCapacity;
	}

	for (size_t i = 0; i < size; i++) {
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

size_t Vector::getSize() const {
	return size;
}

size_t Vector::getCapacity() const {
	return capacity;
}

void Vector::pushBack(const Test& element) {
	upsizeIfNeeded();
	data[size++] = element;
}

void Vector::pushBack(Test&& element) {
	upsizeIfNeeded();
	data[size++] = std::move(element);
}

void Vector::pushAt(const Test& element, size_t index) {
	assertIndex(index);
	upsizeIfNeeded();

	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}

	data[index] = element;
	size++;
}

void Vector::pushAt(Test&& element, size_t index) {
	assertIndex(index);
	upsizeIfNeeded();

	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}

	data[index] = std::move(element);
	size++;
}

Test Vector::popBack() {
	if (empty()) {
		throw std::exception("Vector is empty");
	}
	// Note: the actual std::vector does NOT lower its capacity on this function
	//downsizeIfNeeded();
	// Note: the actual std::vector does NOT return on popback
	return data[--size];
}

Test Vector::popAt(size_t index) {
	assertIndex(index);
	// Note: the actual std::vector does NOT lower its capacity on this function
	downsizeIfNeeded();

	Test temp = data[index];
	size--;
	for (size_t i = index; i < size; i++) {
		data[i] = data[i + 1];
	}

	return temp;
}

bool Vector::empty() const {
	return size == 0;
}

void Vector::clear() {
	size = 0;
}

void Vector::shrinkToFit() {
	resize(size);
}

Test& Vector::operator[](size_t index) {
	assertIndex(index);

	return data[index];
}

const Test& Vector::operator[](size_t index) const {
	assertIndex(index);

	return data[index];
}

void Vector::move(Vector&& other) {
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
}

void Vector::copyFrom(const Vector& other) {
	size = other.size;
	capacity = other.capacity;
	data = new Test[capacity];

	for (size_t i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
}

void Vector::free() {
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}
