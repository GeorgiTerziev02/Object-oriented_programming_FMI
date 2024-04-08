#include "MyString.h"
#include <cstring>

#pragma warning(disable:4996)

namespace {
	constexpr int BUFFER_SIZE = 1024;
    constexpr char INDEX_OUT_OF_RANGE_EXCEPTION_MESSAGE[] = "Index out of range";
}

MyString::MyString(size_t length) : length(length) {
	data = new char[length + 1];
}

MyString::MyString() : MyString((size_t)0) {
	data[0] = '\0';
}

// arr => nullptr
// arr => '\0'
// arr => "adasfa"
MyString::MyString(const char* str)
	: MyString(str ? strlen(str) : 0)
{
	if (!str) {
		data[0] = '\0';
	}
	else {
		strcpy(data, str);
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
	return data;
}

size_t MyString::getLength() const {
	return length;
}

void MyString::free() {
	delete[] data;
	data = nullptr;
	length = 0;
}

void MyString::copyFrom(const MyString& other) {
	length = other.length;
	data = new char[length + 1];
	strcpy(data, other.data);
}

char& MyString::operator[](size_t index) {
	if (index < length) {
		throw std::out_of_range(INDEX_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	return data[index];
}

char MyString::operator[](size_t index) const {
	if (index < length) {
		throw std::out_of_range(INDEX_OUT_OF_RANGE_EXCEPTION_MESSAGE);
	}

	return data[index];
}

MyString& MyString::operator+=(const MyString& other) {
	length += other.length + 1;
	char* temp = new char[length];
	temp[0] = '\0';
	strcat(temp, data);
	strcat(temp, other.data);

	delete[] data;
	data = temp;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const MyString& str) {
	return out << str.c_str();
}

std::istream& operator>>(std::istream& in, MyString& str) {
	char buffer[BUFFER_SIZE];
	in.getline(buffer, BUFFER_SIZE);

	str.length = strlen(buffer);
	delete[] str.data;
	str.data = new char[str.length + 1];
	strcpy(str.data, buffer);

	return in;
}

// Not optimal because we allocate memory twice
// 1. copy constructor
// 2. += deletes the allocated from the copy constructor and allocates new memory
// MyString operator+(const MyString& lhs, const MyString& rhs) {
// 	MyString result(lhs);
// 	result += rhs;
// 	return result;
// }

// With this implementation we allocate memory only once
MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString result(lhs.length + rhs.length + 1);

	result[0] = '\0';
	strcat(result.data, lhs.data);
	strcat(result.data, rhs.data);

	return result;
}

bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}