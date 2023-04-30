#include "UniqueElementPointer.h"
#include <utility>

UniqueElementPointer::UniqueElementPointer(TestClass* ptr) {
	this->ptr = ptr;
}

UniqueElementPointer::UniqueElementPointer(UniqueElementPointer&& other) noexcept {
	move(std::move(other));
}

UniqueElementPointer& UniqueElementPointer::operator=(UniqueElementPointer&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

TestClass* UniqueElementPointer::operator->() {
	return ptr;
}

TestClass& UniqueElementPointer::operator*() {
	return *ptr;
}

TestClass* UniqueElementPointer::get() {
	return this->ptr;
}

void UniqueElementPointer::reset(TestClass* ptr) {
	if (this->ptr == ptr) {
		return;
	}

	free();
	this->ptr = ptr;
}

TestClass* UniqueElementPointer::release() {
	TestClass* temp = ptr;
	ptr = nullptr;
	return temp;
}

UniqueElementPointer::~UniqueElementPointer() {
	free();
}

void UniqueElementPointer::move(UniqueElementPointer&& other) noexcept {
	ptr = other.ptr;
	other.ptr = nullptr;
}

void UniqueElementPointer::free() {
	delete ptr;
}
