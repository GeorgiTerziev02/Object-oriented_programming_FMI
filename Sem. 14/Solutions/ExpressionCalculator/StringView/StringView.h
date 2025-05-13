#pragma once
#include <iostream>
#include "MyString.h"

class StringView {
private:
	const char* start;
	const char* end;

public:
	StringView(const char* str);
	StringView(const MyString& str);
	StringView(const char* start, const char* end);

	size_t length() const;
	char operator[](size_t index) const;
	StringView substr(size_t fromIndex, size_t length) const;

	friend std::ostream& operator<<(std::ostream& os, const StringView& view);

	friend int compare(const StringView& lhs, const StringView& rhs);
};

bool operator<(const StringView& lhs, const StringView& rhs);
bool operator<=(const StringView& lhs, const StringView& rhs);
bool operator>=(const StringView& lhs, const StringView& rhs);
bool operator>(const StringView& lhs, const StringView& rhs);
bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);