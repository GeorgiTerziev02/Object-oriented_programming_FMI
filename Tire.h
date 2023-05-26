#pragma once
#include "CarPart.h"
class Tire: public CarPart
{
	size_t width;
	size_t profile;
	size_t diameter;
public:
	Tire() = default;
	Tire(const MyString& name,const MyString& desc, size_t width, size_t profile, size_t diameter);
	void setWidth(size_t width);
	void setProfile(size_t profile);
	void setDiameter(size_t diameter);

	size_t getWidth()const;
	size_t getProfile() const;
	size_t getDiameter()const;
	friend void operator<<(std::ostream& out, const Tire& currTire);

};
void operator<<(std::ostream& out, const Tire& currTire);

