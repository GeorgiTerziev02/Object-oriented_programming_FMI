#include "StringPool.h"
#include <cstring>
#include <stdexcept>      // std::out_of_range

#pragma warning(disable : 4996)

namespace {
    const char INVALID_INDEX_ERROR_MESSAGE[] = "Index out of range";
}

StringPool::SmallString::SmallString(const char* str) {
	strcpy(
        data,
        strlen(str) > StringPoolConstants::SMALL_STRING_MAX_LENGTH ? "" : str
    );
}

const char* StringPool::SmallString::c_str() const {
	return data;
}

const size_t StringPool::SmallString::getRefsCount() const {
	return refsCount;
}

bool StringPool::SmallString::operator==(const SmallString& other) const {
	return compare(*this, other) == 0;
}
bool StringPool::SmallString::operator<(const SmallString& other) const {
	return compare(*this, other) == -1;
}

int compare(const StringPool::SmallString& lhs, const StringPool::SmallString& rhs){
	return strcmp(lhs.c_str(), rhs.c_str());
}

void StringPool::resize() {
	SmallString** temp = new SmallString * [capacity *= 2];
	for (size_t i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

long long StringPool::find(const SmallString& str) const {
	// binary search to find the leftmost pointer
	long long left = 0, right = size - 1;
	long long result = -1;

	while (left <= right) {
		long long mid = left + (right - left) / 2;
		int comparisonResult = compare(*data[mid], str);
		if (comparisonResult == 0) { // ==
			result = mid;
			right = mid - 1;
		}
		else if (comparisonResult == -1) { // <
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

StringPool::StringPool() : capacity(StringPoolConstants::INITIAL_CAPACITY) {
	data = new SmallString * [capacity];
}

StringPool::StringPool(const StringPool& other) {
	copyFrom(other);
}

StringPool& StringPool::operator=(const StringPool& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

StringPool::~StringPool() {
	free();
}

size_t StringPool::getSize() const {
	return size;
}

void StringPool::insert(const SmallString& str) {
	if (size == capacity) {
		resize();
	}

	size_t placementIndex = size;
	while (placementIndex != 0 && str < *data[placementIndex - 1]) {
		data[placementIndex] = data[placementIndex - 1];
		placementIndex--;
	}

	if (placementIndex != 0 && *data[placementIndex - 1] == str) {
		data[placementIndex] = data[placementIndex - 1];
		data[placementIndex]->refsCount++;
	}
	else {
		data[placementIndex] = new SmallString(str);
	}

	size++;
}

void StringPool::removeAt(size_t index) {
	if (index >= size) {
		throw std::out_of_range(INVALID_INDEX_ERROR_MESSAGE);
	}
	// if was last ref -> delete
	// either way we decrement the refsCount with the --
	if (data[index]->refsCount-- == 1) {
		delete data[index];
	}
	// set to null ptr and move to the right
	data[index] = nullptr;
	size--;
	for (size_t i = index; i < size; i++) {
		data[i] = data[i + 1];
	}
}

const StringPool::SmallString& StringPool::operator[](size_t index) const {
	if (index >= size) {
		throw std::out_of_range(INVALID_INDEX_ERROR_MESSAGE);
	}

	return *data[index];
}

void StringPool::copyFrom(const StringPool& other) {
	size = other.size;
	capacity = other.capacity;
	data = new SmallString* [capacity];

	for (size_t i = 0; i < size; i++) {
		if (i == 0 || data[i] != data[i - 1]) {
			data[i] = new SmallString(*other.data[i]);
		}
		else {
			data[i] = data[i - 1];
		}
	}
}

void StringPool::free() {
	for (size_t i = 0; i < size; i++) {
		if (data[i]->refsCount-- == 1) {
			delete data[i];
			data[i] = nullptr;
		}
	}

	delete[] data;
}