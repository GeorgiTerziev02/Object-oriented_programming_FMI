#pragma once
#include <iostream>

class MyString {
private:
	char* str = nullptr;
	size_t length = 0;

	MyString(size_t length);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	const char* c_str() const;
	size_t getLength() const;
    
private:
	void copyFrom(const MyString& other);
	void free();
};
