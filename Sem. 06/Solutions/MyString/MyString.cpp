#include "MyString.h"
#include <cstring>
#include <stdexcept>

#pragma warning (disable : 4996)

MyString::MyString(size_t length): length(length) {
	str = new char[length + 1];
}

MyString::MyString() : MyString((size_t)0) {
	str[0] = '\0';
}
//MyString::MyString() : MyString("") {
//}

MyString::MyString(const char* str): MyString(strlen(str)) {
	strcpy(this->str, str);
}

MyString::MyString(const MyString& other): length(other.length) {
	copyDynamic(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		freeDynamic();
		length = other.length;
		copyDynamic(other);
	}
	return *this;
}

MyString::~MyString() {
	freeDynamic();
}

size_t MyString::getLength() const {
	return length;
}

const char* MyString::c_str() const {
	return str;
}

char& MyString::at(size_t index) {
	if (index >= length) {
		throw std::out_of_range("....");
	}
	return str[index];
}

char MyString::at(size_t index) const {
	if (index >= length) {
		throw std::out_of_range("....");
	}

	return str[index];
}

void MyString::copyDynamic(const MyString& other) {
	str = new char[other.length + 1];
	strcpy(str, other.str);
}

void MyString::freeDynamic() {
	delete[] str;
}
