#pragma once
#include "MyString.h"
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
class CarPart
{
	static size_t GLOBAL_ID;
	size_t identificator;
	MyString name;
	MyString description;
public:
	CarPart() = default;
	CarPart(const MyString& name, const MyString& description);
	void setName(const MyString& name);
	void setDescription(const MyString& description);
	
	const MyString& getName()const;
	const MyString& getDesc()const;
	size_t getIdentificator()const;

	friend void operator<<(std::ostream& out, const CarPart& currPart);
};

void operator<<(std::ostream& out, const CarPart& currPart);
