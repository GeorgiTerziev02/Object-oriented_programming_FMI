#pragma once
#include "CarPart.h"

class Tire: public CarPart
{
private:
	unsigned short width;
	unsigned short profile;
	unsigned short diameter;

	void setWidth(unsigned short width);
	void setProfile(unsigned short profile);
	void setDiameter(unsigned short diameter);

public:
	
	Tire();
	Tire(unsigned int id, const MyString& manufacturer, const MyString& desc, 
		unsigned short width, unsigned short profile, unsigned short diameter);
};