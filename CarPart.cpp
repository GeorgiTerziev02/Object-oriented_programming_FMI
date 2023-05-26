#include "CarPart.h"

size_t CarPart::GLOBAL_ID = 1;

CarPart::CarPart(const MyString& name, const MyString& description) {
	identificator = GLOBAL_ID++;
	setName(name);
	setDescription(description);
}
void CarPart::setName(const MyString& name) {
	this->name = name;
}
void CarPart::setDescription(const MyString& description) {
	this->description = description;
}

const MyString& CarPart::getName()const {
	return name;
}
const MyString& CarPart::getDesc()const {
	return description;
}
size_t CarPart::getIdentificator()const {
	return identificator;
}
void operator<<(std::ostream& out, const CarPart& currPart) {
	out << currPart.getIdentificator() << " by " << currPart.name << " - " << currPart.description;
}
