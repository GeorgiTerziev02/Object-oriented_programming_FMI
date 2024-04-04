#pragma once
#include <iostream>

class MyString
{
    char* data = nullptr;
    size_t length = 0;
    size_t capacity = 15;

    void copyFrom(const MyString& other);
    void free();
    void resize();

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

    MyString& operator+=(const MyString& other);
    MyString& operator+=(char ch);

    char& operator[](size_t index);
    char operator[](size_t index) const;

    operator bool() const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);