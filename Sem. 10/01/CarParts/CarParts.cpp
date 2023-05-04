#include "CarParts.h"

CarPart::CarPart(unsigned id, const MyString& manufacturer, const MyString descrition)
	:id(id), manufacturer(manufacturer), description(description){}

unsigned CarPart::getId() const
{
	return id;
}

MyString CarPart::getManifacturer() const
{
	return manufacturer;
}

MyString CarPart::getDescription() const
{
	return description;
}

void CarPart::print(std::ostream& os) const
{
	os << "(" << id << ") by" << manufacturer << " - " << description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& part)
{
	part.print(os);
	return os;
}
