#pragma once
#include <iostream>

class MyString
{
	char* _data;
	size_t _length;

	void copyFrom(const MyString& data);
	void free();

	static int npos;
	explicit MyString(size_t capacity); //for memory allocation. How much bytes to allocate
public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	MyString(MyString&& other);
	MyString& operator=(MyString&& other);

	size_t length() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	const char* c_str() const;
	int find(const MyString& substr)const;
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend std::istream& getline(std::istream& is, MyString& str);
};
std::istream& getline(std::istream& is, MyString& str);
std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);

