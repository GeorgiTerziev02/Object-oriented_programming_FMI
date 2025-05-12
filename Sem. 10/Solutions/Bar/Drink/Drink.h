#pragma once
#include "MyStringSso.h"

class Drink {
private:
	MyString name;
	size_t ml = 0;

public:
	Drink() {};
	Drink(const MyString& name, size_t ml);

	const MyString& getName() const;
	size_t getMl() const;

	void setName(const MyString& name);
	void setMl(size_t ml);
};