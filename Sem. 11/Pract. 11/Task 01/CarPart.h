#pragma once
#include "MyString.h"

class CarPart
{
private:
	unsigned int id;
	MyString manufacturer;
	MyString description;

public:
	CarPart(unsigned int id, const MyString& manufacturer, const MyString& description);
	virtual ~CarPart();
};