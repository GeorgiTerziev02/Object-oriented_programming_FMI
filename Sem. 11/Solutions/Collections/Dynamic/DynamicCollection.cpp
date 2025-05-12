#include "DynamicCollection.h"
#include <utility>

void DynamicCollection::resize(size_t newCapacity) {
	capacity = newCapacity;
	int* newData = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

DynamicCollection::DynamicCollection() {
	data = new int[capacity];
}

DynamicCollection::DynamicCollection(const DynamicCollection& other) {
	copyFrom(other);
}

DynamicCollection::DynamicCollection(DynamicCollection&& other) noexcept {
	moveFrom(std::move(other));
}

DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicCollection::~DynamicCollection() {
	free();
}

void DynamicCollection::free() {
	delete[] data;
}

void DynamicCollection::copyFrom(const DynamicCollection& other) {
	size = other.size;
	capacity = other.capacity;
	data = new int[capacity];

	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

void DynamicCollection::moveFrom(DynamicCollection&& other) {
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}
