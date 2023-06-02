#pragma once
#include <fstream>
class MyString
{
private:
	char* data;
	size_t len;
public:
	static const size_t npos = -1;

	MyString(const char* str, size_t len);
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	MyString& operator=(const MyString& rhs);
	~MyString();

	MyString& operator+=(const MyString& rhs);

	bool operator==(const MyString& rhs) const;
	bool operator!=(const MyString& rhs) const;
	bool operator<(const MyString& rhs) const;
	bool operator>(const MyString& rhs) const;
	bool operator<=(const MyString& rhs) const;
	bool operator>=(const MyString& rhs) const;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	MyString substr(size_t pos, size_t len) const;
	size_t find(const MyString& str, size_t pos = 0) const;

	const char* c_str() const;
	size_t length() const;
	bool empty() const;

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);

private:
	void copyFrom(const MyString& str);
	void free();
};
MyString operator+(const MyString& lhs, const MyString& rhs);

