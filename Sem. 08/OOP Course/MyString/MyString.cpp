#include "MyString.h"
#include "helpers.h"
#include <iostream>

#pragma warning (disable:4996)

MyString::MyString(const char* str, size_t len) : len(len), data(new char[len + 1])
{
	for (size_t i = 0; i < len; ++i)
	{
		data[i] = str[i];
	}
	data[len] = '\0';
}

MyString::MyString()
{
	data = nullptr;
	len = 0;
}

MyString::MyString(const char* str)
{
	len = strLen(str);
	data = new char[len + 1];
	strCpy(data, str);
}

MyString::MyString(const MyString& str)
{
	copyFrom(str);
}

MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs)
	{
		free();
		copyFrom(rhs);
	}
	return (*this);
}

MyString::~MyString()
{
	free();
}

void MyString::copyFrom(const MyString& str)
{
	len = str.len;
	data = new char[len + 1];
    strCpy(data, str.data);
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
	len = 0;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString string(lhs);
	string += rhs;
	return string;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	char* result = new char[length() + rhs.length() + 1];
	result[0] = '\0'; 
	strCat(result, data);
	strCat(result, rhs.data);

	delete[] data;
	data = result;
	len = length() + rhs.length();

	return *this;
}

bool MyString::operator==(const MyString& rhs) const 
{
	return strCmp(data, rhs.data) == 0;
}

bool MyString::operator!=(const MyString& rhs) const
{
	return strCmp(data, rhs.data) != 0;
}

bool MyString::operator<(const MyString& rhs) const
{
	return strCmp(data, rhs.data) < 0;
}

bool MyString::operator>(const MyString& rhs) const 
{
	return strCmp(data, rhs.data) > 0;
}

bool MyString::operator<=(const MyString& rhs) const
{
	return strCmp(data, rhs.data) <= 0;
}

bool MyString::operator>=(const MyString& rhs) const
{
	return strCmp(data, rhs.data) >= 0;
}

char& MyString::operator[](size_t index)
{
	return data[index];
}

const char& MyString::operator[](size_t index) const 
{
	return data[index];
}

MyString MyString::substr(size_t pos, size_t len) const
{
	if (pos > len)
	{
		throw std::out_of_range("MyString::substr");
	}
	return MyString(data + pos, std::min(len, len - pos));
}

size_t MyString::find(const MyString& str, size_t pos) const 
{
	if (pos > len)
	{
		throw std::out_of_range("MyString::find");
	}
	char* p = strStr(data + pos, str.data);
	if (p == nullptr) 
	{
		return npos;
	}
	return p - data;
}

const char* MyString::c_str() const
{
	return data;
}

size_t MyString::length() const
{
	return len;
}

bool MyString::empty() const
{
	return len == 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.data;
}