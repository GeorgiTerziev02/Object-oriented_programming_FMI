#include "ImmutableString.h"

// Initialize the pool
StringPool ImmutableString::pool;

ImmutableString::ImmutableString() : ImmutableString("") {}

ImmutableString::ImmutableString(const char* text) {
	data = pool.getString(text);
	size = strlen(data);
}

ImmutableString::ImmutableString(const ImmutableString& other) {
	size = other.size;
	data = pool.getString(other.data);
}

ImmutableString::~ImmutableString() {
	pool.removeString(data);
}

char ImmutableString::operator[](size_t index) const {
	if (size <= index) {
		throw std::out_of_range("Index out of range");
	}

	return data[index];
}

ImmutableString& ImmutableString::operator=(const ImmutableString& other) {
	if (this != &other) {
		pool.removeString(data);
		data = pool.getString(other.data);
		size = other.size;
	}

	return *this;
}

const char* ImmutableString::c_str() const {
	return data;
}

size_t ImmutableString::length() const {
	return size;
}
bool ImmutableString::empty() const {
	return size == 0;
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs) {
	// we can directly compare the addresses of the two pointers
	// if the two strings are the same => the two pointers will point at the address
	return lhs.data == rhs.data;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs) {
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str) {
	return os << str.c_str();
}

ImmutableString operator+(const ImmutableString& lhs, const ImmutableString& rhs) {
	char* temp = new char[lhs.size + rhs.size + 1];
	strcpy(temp, lhs.data);
	strcat(temp, rhs.data);

	ImmutableString result(temp);
	delete[] temp;
	return result;
}