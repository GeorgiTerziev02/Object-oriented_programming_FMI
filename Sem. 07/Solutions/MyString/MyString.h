#pragma once
#include <iostream>

class MyString {
private:
    char* data;
    size_t length;
    size_t capacity;

	void validateIndex(size_t index) const;
    void resize(size_t lengthToFit);

    explicit MyString(size_t capacity);
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    size_t getLength() const;
    size_t getCapacity() const;
    const char* c_str() const;

	char& at(size_t index);
	char at(size_t index) const;
    // const char& at(size_t index) const; alternative
    char& operator[](size_t index);
    char operator[](size_t index) const;

    // this is not in the standard
    operator bool() const;

    MyString& operator+=(const MyString& other);
    MyString& operator+=(char ch);

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::istream& operator>>(std::istream& is, MyString& str);

private:
	void copyDynamic(const MyString& other);
	void freeDynamic();
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);