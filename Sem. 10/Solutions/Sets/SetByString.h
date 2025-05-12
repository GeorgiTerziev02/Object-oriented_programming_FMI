#pragma once

#include "Bitset.h"

class SetByString : private Bitset {
private:
	char* str = nullptr;
	size_t length = 0;

	void fillSet();
	void copyString(const char* str);
public:
	SetByString(unsigned int max, const char* str);
	SetByString(const SetByString& other);
	SetByString(SetByString&& other) noexcept;
	SetByString& operator=(const SetByString& other);
	SetByString& operator=(SetByString&& other) noexcept;
	~SetByString();

	bool contains(unsigned n) const;
	void print() const;
	void setString(const char* str);
	void setAt(size_t index, char ch);

private:
	void copyFrom(const SetByString& other);
	void free();
	void moveFrom(SetByString&& other) noexcept;
};

