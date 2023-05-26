#include "MyString.h"

#pragma warning(disable : 4996)

int MyString::npos = -1;

MyString::MyString(size_t capacity)
{
	_length = capacity - 1;
	_data = new char[capacity];
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs._length + rhs._length + 1);

	result[0] = '\0';
	strcat(result._data, lhs._data);
	strcat(result._data, rhs._data);

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[(_length += other._length) + 1];
	result[0] = '\0';
	strcat(result, _data);
	strcat(result, other._data);

	delete[] _data;
	_data = result;

	return *this;
}

MyString::MyString() : MyString(1)
{
	_data[0] = '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	strcpy(_data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


void MyString::free()
{
	delete[] _data;
	_data = nullptr;
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return _length;
}

void MyString::copyFrom(const MyString& other)
{
	_length = other._length;
	_data = new char[_length + 1];
	strcpy(_data, other._data);
}

MyString::MyString(MyString&& other)
{
	_data = other._data;
	other._data = nullptr;
	_length = other._length;
}

MyString& MyString::operator=(MyString&& other)
{
	if (this != &other)
	{
		free();
		_data = other._data;
		other._data = nullptr;
		_length = other._length;
	}
	return *this;
}

char& MyString::operator[](size_t index) //Неконстантен достъп
{
	return _data[index];
}

char MyString::operator[](size_t index) const //Константен достъп 
{
	return _data[index];
}

MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > _length)
		throw std::length_error("Error, Substr out of range");


	MyString res(howMany + 1);
	for (int i = 0; i < howMany; i++)
		res._data[i] = _data[begin + i];
	res[howMany] = '\0';
	return res;
}

const char* MyString::c_str() const
{
	return _data;
}

std::istream& getline(std::istream& is, MyString& str)
{
	char buff[1024];
	is.getline(buff, 1014);// is.getLine(buff, 1024);
	delete[] str._data;
	str._length = strlen(buff);
	str._data = new char[str._length + 1];
	strcpy(str._data, buff);
	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff; // is.getLine(buff, 1024);
	delete[] str._data;
	str._length = strlen(buff);
	str._data = new char[str._length + 1];
	strcpy(str._data, buff);
	return is;
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
const char* my_strstr(const char* str, const char* substr) {
	if (*substr == '\0') {
		return str;
	}

	while (*str != '\0') {
		const char* s = str;
		const char* t = substr;

		while (*t != '\0' && *s == *t) {
			s++;
			t++;
		}

		if (*t == '\0') {
			return str;
		}

		str++;
	}

	return nullptr;
}
int MyString::find(const MyString& substr) const {

	const char* result = my_strstr(_data, substr.c_str());
	if (result == nullptr) {
		return npos;
	}

	return result - _data;
}
