#include "MyString.h"
#include <iostream>

#pragma warning(disable:4996)

MyString::MyString(size_t length) : length(length) {
	str = new char[length + 1];
}

MyString::MyString() : MyString((size_t)0) {
	str[0] = '\0';
}

MyString::MyString(const char* str) : MyString(str ? strlen(str) : 0) {
	if (!str) {
		this->str[0] = '\0';
	}
	else {
		strcpy(this->str, str);
	}
}

MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::~MyString() {
	free();
}

const char* MyString::c_str() const {
	return str;
}

size_t MyString::getLength() const {
	return length;
}

void MyString::copyFrom(const MyString& other) {
	length = other.length;
	str = new char[length + 1];
	strcpy(str, other.str);
}

void MyString::free() {
	delete[] str;
	length = 0;
}