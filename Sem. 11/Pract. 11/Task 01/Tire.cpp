#include "Tire.h"

Tire::Tire(unsigned int id, const MyString& manufacturer, const MyString& desc,
	unsigned short width, unsigned short profile, unsigned short diameter): CarPart(id, manufacturer, desc){

	setWidth(width);
	setProfile(profile);
	setDiameter(diameter);
}

Tire::Tire(): CarPart(0, "", ""), width(0), profile(0), diameter(0) {}

void Tire::setWidth(unsigned short width) {
	if (width < 155 || width > 365) {
		throw std::length_error("Invalid tire width!");
	}
	this->width = width;
}

void Tire::setProfile(unsigned short profile) {
	if (profile < 30 || profile > 80) {
		throw std::length_error("Invalid tire profile!");
	}
	this->profile = profile;
}

void Tire::setDiameter(unsigned short diameter) {
	if (diameter < 30 || diameter > 80) {
		throw std::length_error("Invalid tire diameter!");
	}
	this->diameter = diameter;
}