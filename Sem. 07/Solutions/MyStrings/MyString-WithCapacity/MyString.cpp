#include "String.h"
#include <cstring>
#pragma warning(disable:4996)

void MyString::copyFrom(const MyString& other)
{
    length = other.length;
    capacity = other.capacity;
    data = new char[capacity + 1];
    strcpy(data, other.data);
}

void MyString::free()
{
    delete[] data;
    data = nullptr;
    length = capacity = 0;
}

void MyString::resize()
{
    capacity = (capacity + 1) * 2 - 1;

    char* newData = new char[capacity + 1];
    strcpy(newData, data);
    delete[] data;

    data = newData;
}

MyString::MyString(size_t cap)
{
    capacity = cap;
    length = 0;
    data = new char[capacity + 1];
}

MyString::MyString() : MyString("")
{
}

MyString::MyString(const char* str)
{
    if (!str)
    {
        data = new char[capacity + 1];
        data[0] = '\0';
    }
    else
    {
        length = strlen(str);
        capacity = std::max((int)getNextPowerOfTwo(length), 16) - 1;
        data = new char[capacity + 1];
        strcpy(data, str);
    }
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::getLength() const
{
    return length;
}

size_t MyString::getCapacity() const
{
    return capacity;
}

const char* MyString::c_str() const
{
    return data;
}

MyString& MyString::operator+=(const MyString& other)
{
    length += other.length;

    if (length <= capacity) {
        strcat(data, other.data);
        return *this;
    }

    capacity = getNextPowerOfTwo(length) - 1;
    char* res = new char[capacity + 1];
    strcpy(res, data);
    strcat(res, other.data);

    delete[] data;
    data = res;

    return *this;
}

MyString& MyString::operator+=(char ch)
{
    if (length == capacity) {
        resize();
    }
    data[length++] = ch;
    return *this;
}

char& MyString::operator[](size_t index)
{
    return data[index];
}

char MyString::operator[](size_t index) const
{
    return data[index];
}

MyString::operator bool() const
{
    return length == 0;
}

unsigned int getNextPowerOfTwo(unsigned int n)
{
    unsigned int step = 1;

    while ((n >> step) > 0) {
        n |= n >> step;
        step *= 2;
    }

    return n + 1;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    size_t length = lhs.length + rhs.length;
    size_t capacity = getNextPowerOfTwo(length) - 1;

    MyString res(capacity);
    strcpy(res.data, lhs.data);
    strcat(res.data, rhs.data);

    return res;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char buff[1024];
    is >> buff;

    delete[] str.data;
    str.length = strlen(buff);
    str.capacity = std::max((int)getNextPowerOfTwo(str.length), 16) - 1;
    str.data = new char[str.capacity + 1];
    strcpy(str.data, buff);

    return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.c_str();
    return os;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}