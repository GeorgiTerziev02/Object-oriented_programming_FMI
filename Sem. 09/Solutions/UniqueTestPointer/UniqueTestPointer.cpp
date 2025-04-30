#include "UniqueTestPointer.h"

#include <utility>

UniqueTestPointer::UniqueTestPointer(Test* resource) : resource(resource) {}

UniqueTestPointer::UniqueTestPointer(UniqueTestPointer&& other) noexcept {
	moveFrom(std::move(other));
}

UniqueTestPointer& UniqueTestPointer::operator=(UniqueTestPointer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

UniqueTestPointer::~UniqueTestPointer() {
	free();
}

Test* UniqueTestPointer::operator->() {
	return resource;
}

const Test* UniqueTestPointer::operator->() const {
	return resource;
}

Test& UniqueTestPointer::operator*() {
	return *resource;
}

const Test& UniqueTestPointer::operator*() const {
	return *resource;
}

Test* UniqueTestPointer::get() const {
	return resource;
}

void UniqueTestPointer::reset(Test* newPtr) {
	if (resource == newPtr) {
		return;
	}

	free();
	resource = newPtr;
}

Test* UniqueTestPointer::release() {
	Test* currentPtr = resource;
	resource = nullptr;
	return currentPtr;
}

void UniqueTestPointer::swap(UniqueTestPointer& other) {
	std::swap(resource, other.resource);
}

UniqueTestPointer::operator bool() const {
	return resource;
}

void UniqueTestPointer::free() {
	delete resource;
}

void UniqueTestPointer::moveFrom(UniqueTestPointer&& other) noexcept {
	resource = other.resource;
	other.resource = nullptr;
}