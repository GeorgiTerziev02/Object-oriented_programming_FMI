#pragma once
#include "CarParts.h"
class Tyre : public CarPart
{
private:
	unsigned width;
	unsigned profile;
	unsigned dm;
	double coefficientOfFriction;
public:
	Tyre();
	Tyre(unsigned id, const MyString& manufacturer, const MyString& description, unsigned widht, unsigned profile, unsigned dm, double coefficientOfFriction);
	unsigned getWidth() const;
	unsigned getProfile() const;
	unsigned getDm() const;
	double getTraction() const;

	void setWidth(unsigned width);
	void setProfile(unsigned profile);
	void setDm(unsigned dm);

	void print(std::ostream& os) const override;
};