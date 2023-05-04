#pragma once
#include "MyString.h"

class CarPart
{
private:
	unsigned id;
	MyString manufacturer;
	MyString description;
public:
	CarPart(unsigned id, const MyString& manufacturer, const MyString descrition);
	unsigned getId() const;
	MyString getManifacturer() const;
	MyString getDescription() const;

	virtual void print(std::ostream& os) const;
	friend std::ostream& operator << (std::ostream& os, const CarPart& part);
};

std::ostream& operator << (std::ostream& os, const CarPart& part);
