#pragma once
#include <iostream>

class MyString {
private:
	char* data;
	size_t length;

	// for memory allocation only!
	// allocates length + 1
	explicit MyString(size_t length);

public:
	MyString();
	MyString(const char* arr);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	const char* c_str() const;
	size_t getLength() const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	MyString& operator+=(const MyString& other);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream& in, MyString& str);
private:
	void free();
	void copyFrom(const MyString& other);
};

std::ostream& operator<<(std::ostream& out, const MyString& str);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);