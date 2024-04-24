#include "Drink.h"

Drink::Drink(const MyString& name, size_t ml)
	: name(name), ml(ml) {}

const MyString& Drink::getName() const {
	return name;
}
size_t Drink::getMl() const {
	return ml;
}

void Drink::setName(const MyString& name) {
	this->name = name;
}
void Drink::setMl(size_t ml) {
	this->ml = ml;
}