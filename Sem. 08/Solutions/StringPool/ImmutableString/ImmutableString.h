#pragma once
#include <iostream>
#include "../StringPool/StringPool.h"

class ImmutableString {
private:
	const char* data;
	unsigned size;

	static StringPool pool;

public:
	ImmutableString();
	ImmutableString(const char* text);
	ImmutableString(const ImmutableString& other);
	~ImmutableString();

	char operator[](size_t index) const;

	ImmutableString& operator=(const ImmutableString& other);

	const char* c_str() const;

	size_t length() const;
	bool empty() const;

	// !!!
	friend bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
	// !!!
	friend ImmutableString operator+(const ImmutableString& lhs, const ImmutableString& rhs);
};

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
std::ostream& operator<<(std::ostream& os, const ImmutableString& str);