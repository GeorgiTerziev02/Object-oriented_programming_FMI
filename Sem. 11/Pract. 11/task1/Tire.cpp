#include "Tire.h"

Tire::Tire(const MyString& name, const MyString& desc, size_t width, size_t profile, size_t diameter) : CarPart(name, desc) {
	setWidth(width);
	setProfile(profile);
	setDiameter(diameter);
}
void Tire::setWidth(size_t width) {
	if (width > 155 && width < 365) {
		this->width = width;
	}
	else throw"Invalid value";
}
void Tire::setProfile(size_t profile) {
	if (width > 30 && width < 80) {
		this->width = width;
	}
	else throw"Invalid value";
}
void Tire::setDiameter(size_t diameter) {
	if (width > 13 && width < 21) {
		this->width = width;
	}
	else throw"Invalid value";
}

size_t Tire::getWidth()const {
	return width;
}
size_t Tire::getProfile() const {
	return profile;
}
size_t Tire::getDiameter()const {
	return diameter;
}
void operator<<(std::ostream& out, const Tire& currTire) {
	out << (CarPart)currTire;
	out << currTire.width << "/" << currTire.profile << "R" << currTire.diameter << std::endl;
}